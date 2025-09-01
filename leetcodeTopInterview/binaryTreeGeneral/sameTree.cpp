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

bool isSameTree(TreeNode *p, TreeNode *q)
{
    // the order of checks matter
    if (!p && !q)
        return true;
    if (!p || !q)
        return false;

    return ((p->val == q->val) &&
            isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
}

int main()
{

    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);

    TreeNode *rootI = new TreeNode(3);
    rootI->left = new TreeNode(9);
    rootI->right = new TreeNode(20);

    cout << isSameTree(root, rootI) << endl;

    return 0;
}