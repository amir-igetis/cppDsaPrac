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

void inorder(TreeNode *root, int &count)
{
    // If current node is null, stop recursion
    if (!root)
    {
        return;
    }
    // Increment count for current node
    count++;
    // Recursively count nodes in left subtree
    inorder(root->left, count);
    // Recursively count nodes in right subtree
    inorder(root->right, count);
}

// Function to count total number of nodes
int countNodes(TreeNode *root)
{
    // If tree is empty, return 0
    if (!root)
    {
        return 0;
    }
    // Array used to pass count by reference
    int count = 0;
    // Perform inorder traversal to count nodes
    inorder(root, count);
    // Return the count value
    return count;
} // tc & sc O(n)

///  striver code

// tc O(log n * log n) and sc O(h) or O(n)

// Helper to find height from leftmost path
int findHeightLeftI(TreeNode *node)
{
    int height = 0;
    while (node)
    {
        height++;
        node = node->left;
    }
    return height;
}

// Helper to find height from rightmost path
int findHeightRightI(TreeNode *node)
{
    int height = 0;
    while (node)
    {
        height++;
        node = node->right;
    }
    return height;
}

int countNodesI(TreeNode *root)
{
    // If tree is empty, return 0
    if (!root)
    {
        return 0;
    }
    // Get left height
    int lh = findHeightLeftI(root);
    // Get right height
    int rh = findHeightRightI(root);
    // If heights match, use perfect binary tree formula
    if (lh == rh)
    {
        return (1 << lh) - 1;
    }
    // Otherwise, recursively count left and right subtrees
    return 1 + countNodesI(root->left) + countNodesI(root->right);
}

int main()
{

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(10);
    root->left->left->right = new TreeNode(5);
    root->left->left->right->right = new TreeNode(6);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(10);

    cout << countNodesI(root) << endl;

    return 0;
}