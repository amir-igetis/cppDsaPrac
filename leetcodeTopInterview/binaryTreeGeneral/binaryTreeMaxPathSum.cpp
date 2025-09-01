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

int maxSum;

int maxPathSumHelper(TreeNode *node)
{
    if (!node)
        return 0;

    int leftSum = max(maxPathSumHelper(node->left), 0);
    int rightSum = max(maxPathSumHelper(node->right), 0);

    maxSum = max(maxSum, node->val + leftSum + rightSum);

    return node->val + max(leftSum, rightSum);
}

int maxPathSum(TreeNode *root)
{
    maxSum = INT_MIN;
    maxPathSumHelper(root);
    return maxSum;
}

int main()
{

    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);

    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);

    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->right = new TreeNode(1);

    int ans = maxPathSum(root);
    cout << ans << endl;

    return 0;
}