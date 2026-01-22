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

bool isIdentical(TreeNode *root, TreeNode *node)
{
    if (!root && !node)
        return true;
    if (!root || !node)
        return false;
    return ((root->val == node->val) &&
            isIdentical(root->left, node->left) &&
            isIdentical(root->right, node->right));
}

int main()
{

    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(17);

    cout << (isIdentical(root->left, root->right) ? "True" : "False") << endl;

    return 0;
}