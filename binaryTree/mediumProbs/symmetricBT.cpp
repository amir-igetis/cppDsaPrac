#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {};
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {};
};

bool isSymmetric(TreeNode *curr, TreeNode *node)
{
    if (!curr || !node)
        return curr == node;
    return (curr->val == node->val) && (isSymmetric(curr->left, node->right) && isSymmetric(curr->right, node->left));
}

bool isSymmetricMain(TreeNode *root)
{
    if (!root)
        return true;
    return isSymmetric(root->left, root->right);
}

int main()
{

    struct TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);

    root->right = new TreeNode(2);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    bool res = isSymmetricMain(root);
    if (res)
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}