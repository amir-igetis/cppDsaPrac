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

// Check if a tree is a BST
bool isBST(TreeNode *root, int minVal, int maxVal)
{
    if (root == nullptr)
        return true;

    if (root->val <= minVal || root->val >= maxVal)
        return false;

    return isBST(root->left, minVal, root->val) &&
           isBST(root->right, root->val, maxVal);
}

// Find size of largest BST in a Binary Tree
int largestBST(TreeNode *root)
{
    if (root == nullptr)
        return 0;

    int left = largestBST(root->left);
    int right = largestBST(root->right);

    if (isBST(root, INT_MIN, INT_MAX))
        return left + right + 1;

    return max(left, right);
}

// Inorder print (utility)
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

    cout << largestBST(root) << endl;

    return 0;
}
