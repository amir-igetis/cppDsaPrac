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

// gfg
TreeNode *lca(TreeNode *root, int p, int q)
{
    TreeNode *temp = root;
    if (!root)
        return root;
    while (!temp)
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

// leetcode
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root->val > max(p->val, q->val))
        return lowestCommonAncestor(root->left, p, q);
    if (root->val < min(p->val, q->val))
        return lowestCommonAncestor(root->right, p, q);
    return root;
}

int main()
{

    TreeNode *root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);
    root->right = new TreeNode(8);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);

    // root->right->right = new TreeNode(10);

    // [ 6, 2, 8, 0, 4, 7, 9, null, null, 3, 5 ]

    int p = 2,
        q = 8;

    TreeNode *ans = lca(root, p, q);
    cout << ans->val << endl;

    return 0;
}