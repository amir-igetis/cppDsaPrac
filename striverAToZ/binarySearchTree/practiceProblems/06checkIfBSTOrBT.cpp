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

bool helper(TreeNode *root, int min, int max)
{
    if (!root)
        return true;

    if (root->val >= max || root->val <= min)
        return false;
    bool left = helper(root->left, min, max);
    bool right = helper(root->right, min, max);
    return (left && right);
}

bool isBST(TreeNode *root)
{
    int maxi = INT_MAX;
    int mini = INT_MIN;
    return helper(root, mini, maxi);
}

int main()
{

    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(8);
    root->right = new TreeNode(15);
    root->right->right = new TreeNode(17);

    cout << (isBST(root) ? "TRUE" : "FALSE") << endl;

    return 0;
}