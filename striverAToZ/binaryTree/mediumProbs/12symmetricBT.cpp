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

bool helper(TreeNode *left, TreeNode *right)
{
    if (!left || !right)
        return left == right;
    return ((left->val == right->val) &&
            helper(left->left, right->right) &&
            helper(left->right, right->left));
}

bool isSymmetric(TreeNode *root)
{
    if (!root)
        return true;
    return helper(root->left, root->right);
}

int main()
{

    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(17);

    cout << (isSymmetric(root) ? "True" : "False") << endl;

    return 0;
}