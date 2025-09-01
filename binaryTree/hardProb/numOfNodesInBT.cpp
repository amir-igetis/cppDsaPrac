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

int leftHeight(TreeNode *node)
{
    int height = 0;
    while (node)
    {
        height++;
        node = node->left;
    }
    return height;
}

int rightHeight(TreeNode *node)
{
    int height = 0;
    while (node)
    {
        height++;
        node = node->right;
    }
    return height;
}

int countTreeNode(TreeNode *root)
{
    if (!root)
        return 0;
    int lh = leftHeight(root);
    int rh = rightHeight(root);
    if (lh == rh)
        return (1 << lh) - 1;

    return 1 + countTreeNode(root->left) + countTreeNode(root->right);
}

int main()
{

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    // root->right->right = new TreeNode(6);

    cout << countTreeNode(root) << endl;
    return 0;
}