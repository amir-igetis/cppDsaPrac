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

TreeNode *lca(TreeNode *root, int p, int q)
{
    TreeNode *temp = root;
    if (!root)
        return root;
    while (temp)
    {
        if (p < temp->val && q < temp->val)
            temp = temp->left;
        else if (p > temp->val && q > temp->val)
            temp = temp->right;
        else
            return temp;
    }

    return root;
}

int main()
{

    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(8);
    root->right = new TreeNode(15);
    root->right->right = new TreeNode(17);

    cout << lca(root, 17, 5)->val << endl;

    return 0;
}