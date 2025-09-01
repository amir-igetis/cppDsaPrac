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

bool solve(TreeNode *root, int min, int max)
{
    if (!root)
        return true;
    if (root->val >= max || root->val <= min)
        return false;
    bool left = solve(root->left, min, root->val);
    bool right = solve(root->right, root->val, max);
    return (left && right);
}

bool isBST(TreeNode *root)
{
    int max = INT_MAX;
    int min = INT_MIN;
    return solve(root, min, max);
}

// leetcode

bool isValidBSTHelper(TreeNode *root, TreeNode *minTreeNode, TreeNode *maxTreeNode)
{
    if (!root)
        return true;
    if (!minTreeNode && root->val <= minTreeNode->val)
        return false;
    if (!maxTreeNode && root->val >= maxTreeNode->val)
        return false;

    return isValidBSTHelper(root->left, minTreeNode, root) && isValidBSTHelper(root->right, root, maxTreeNode);
}

bool isValidBST(TreeNode *root)
{
    return isValidBSTHelper(root, nullptr, nullptr);
}



int main()
{
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(10);

    cout << isValidBST(root) << endl;

    return 0;
}