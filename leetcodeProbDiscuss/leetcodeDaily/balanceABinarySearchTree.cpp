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

//    inorder + recursive  TC & SC O(N)
class Solution
{
public:
    TreeNode *balanceBST(TreeNode *root)
    {
        vector<int> inorder;
        inorderTrav(root, inorder);
        return createBalancedBST(inorder, 0, inorder.size() - 1);
    }

private:
    void inorderTrav(TreeNode *root, vector<int> &inorder)
    {
        if (!root)
            return;
        inorderTrav(root->left, inorder);
        inorder.push_back(root->val);
        inorderTrav(root->right, inorder);
    }

    TreeNode *createBalancedBST(vector<int> &inorder, int start, int end)
    {
        if (start > end)
            return nullptr;
        int mid = start + (end - start) / 2;
        TreeNode *leftSubtree = createBalancedBST(inorder, start, mid - 1);
        TreeNode *rightSubtree = createBalancedBST(inorder, mid + 1, end);
        TreeNode *node = new TreeNode(
            inorder[mid], leftSubtree, rightSubtree);
        return node;
    }
};

//    Day stout warren algo / In place balancing TC & SC O(n) & O(n)
class SolutionI
{
public:
    TreeNode *balanceBST(TreeNode *root)
    {
        if (!root)
            return nullptr;

        // Step 1: Create the backbone (vine)
        // Temporary dummy node
        TreeNode *vineHead = new TreeNode(0);
        vineHead->right = root;
        TreeNode *current = vineHead;
        while (current->right)
        {
            if (current->right->left)
            {
                rightRotate(current, current->right);
            }
            else
            {
                current = current->right;
            }
        }

        // Step 2: Count the nodes
        int nodeCount = 0;
        current = vineHead->right;
        while (current)
        {
            ++nodeCount;
            current = current->right;
        }

        // Step 3: Create a balanced BST
        int m = pow(2, floor(log2(nodeCount + 1))) - 1;
        makeRotations(vineHead, nodeCount - m);
        while (m > 1)
        {
            m /= 2;
            makeRotations(vineHead, m);
        }

        TreeNode *balancedRoot = vineHead->right;
        // Delete the temporary dummy node
        delete vineHead;
        return balancedRoot;
    }

private:
    // Function to perform a right rotation
    void rightRotate(TreeNode *parent, TreeNode *node)
    {
        TreeNode *tmp = node->left;
        node->left = tmp->right;
        tmp->right = node;
        parent->right = tmp;
    }

    // Function to perform a left rotation
    void leftRotate(TreeNode *parent, TreeNode *node)
    {
        TreeNode *tmp = node->right;
        node->right = tmp->left;
        tmp->left = node;
        parent->right = tmp;
    }

    // Function to perform a series of left rotations to balance the vine
    void makeRotations(TreeNode *vineHead, int count)
    {
        TreeNode *current = vineHead;
        for (int i = 0; i < count; ++i)
        {
            TreeNode *tmp = current->right;
            leftRotate(current, tmp);
            current = current->right;
        }
    }
};

vector<int> printList(TreeNode *root)
{

    vector<int> ans;
    if (!root)
        return ans;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode *node = q.front();
            q.pop();
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);

            ans.push_back(node->val);
        }
    }
    return ans;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->left->left = new TreeNode(4);

    Solution sol;
    SolutionI solI;

    // TreeNode *ans = sol.balanceBST(root);
    TreeNode *ans = solI.balanceBST(root);
    vector<int> arr = printList(ans);
    for (auto &i : arr)
        cout << i << " ";
    cout << endl;

    return 0;
}