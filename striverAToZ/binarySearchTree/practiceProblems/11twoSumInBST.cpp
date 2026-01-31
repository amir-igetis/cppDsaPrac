#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void inorderTrav(TreeNode *root, vector<int> &inorder)
{
    if (!root)
        return;
    inorderTrav(root->left, inorder);
    inorder.push_back(root->val);
    inorderTrav(root->right, inorder);
}

// brute force tc O(N + N) and sc O(N)
bool findTarget(TreeNode *root, int k)
{
    vector<int> inorder;
    inorderTrav(root, inorder);
    int left = 0;
    int right = inorder.size() - 1;
    while (left < right)
    {
        int sum = inorder[left] + inorder[right];
        if (sum == k)
            return true;
        else if (sum < k)
            left++;
        else
            right--;
    }
    return false;
}

// optimal approach tc O(n) and sc O(h)
class BSTIterator
{
private:
    // A stack is used to keep track of nodes while traversing
    stack<TreeNode *> myStack;
    // This flag tells whether we are moving forward (inorder) or backward (reverse inorder)
    bool reverse;

public:
    // Constructor initializes the iterator with the root node and traversal direction
    BSTIterator(TreeNode *root, bool isReverse) : reverse(isReverse)
    {
        // Push all nodes on one side (left or right) into the stack
        pushAll(root);
    }

    // This function checks if there are more nodes left to visit
    bool hasNext()
    {
        // If the stack is not empty, there are still nodes left
        return !myStack.empty();
    }

    // This function returns the next node’s value in the chosen order
    int next()
    {
        // Get the node on top of the stack
        TreeNode *tmpNode = myStack.top();
        // Remove this node from the stack
        myStack.pop();

        // If we are not in reverse mode, we need to go right after visiting a node
        if (!reverse)
        {
            pushAll(tmpNode->right);
        }
        // If we are in reverse mode, we need to go left after visiting a node
        else
        {
            pushAll(tmpNode->left);
        }

        // Return the value of the node that was just visited
        return tmpNode->val;
    }

private:
    // This helper function pushes all nodes from the current node down to the left/right edge
    void pushAll(TreeNode *node)
    {
        // Keep going until we reach a null node
        while (node != nullptr)
        {
            // Push the node onto the stack
            myStack.push(node);
            // If reverse is true, move to the right child
            if (reverse)
            {
                node = node->right;
            }
            // Otherwise, move to the left child
            else
            {
                node = node->left;
            }
        }
    }
};

// This class contains the solution logic to check if a target sum exists in BST
class Solution
{
public:
    // This function checks if two nodes in BST sum to k
    bool findTarget(TreeNode *root, int k)
    {
        // If tree is empty, return false immediately
        if (!root)
            return false;

        // Create two iterators: one for smallest-to-largest order, another for largest-to-smallest
        BSTIterator l(root, false);
        BSTIterator r(root, true);

        // Get first values from both ends
        int i = l.next();
        int j = r.next();

        // Loop until the two pointers meet
        while (i < j)
        {
            // If the two numbers add up to k, we found a pair
            if (i + j == k)
                return true;
            // If sum is too small, move left iterator forward
            else if (i + j < k)
                i = l.next();
            // If sum is too large, move right iterator backward
            else
                j = r.next();
        }

        // If no pair found, return false
        return false;
    }
};

void printList(TreeNode *root)
{
    if (!root)
        return;
    printList(root->left);
    cout << root->val << " ";
    printList(root->right);
}

int main()
{

    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(8);
    root->right = new TreeNode(15);
    root->right->right = new TreeNode(17);
    TreeNode *rootI = new TreeNode(12);
    rootI->left = new TreeNode(9);

    printList(root);

    int target = 28;
    bool exist = findTarget(root, target);
    cout << (exist ? "TRUE" : "FALSE") << endl;

    return 0;
}