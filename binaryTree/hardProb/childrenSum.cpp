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

int isSumProperty(TreeNode *root)
{
    if (!root || (!root->left && !root->right))
        return 1;

    int leftdata = 0, rightdata = 0;

    if (root->left)
        leftdata = root->left->val;

    if (root->right)
        rightdata = root->right->val;
    if (root->val == leftdata + rightdata)
    {
        if (isSumProperty(root->left) && isSumProperty(root->right))
            return 1;
    }

    return 0;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->left->left = new TreeNode(5);
    root->left->left->left = new TreeNode(7);
    root->right = new TreeNode(2);
    root->right->right = new TreeNode(4);
    root->right->right = new TreeNode(6);

    cout << isSumProperty(root) << endl;
    return 0;
}