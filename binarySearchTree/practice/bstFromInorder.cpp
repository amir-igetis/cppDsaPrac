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

TreeNode *helper(TreeNode *root, int k)
{
    if (!root)
        return new TreeNode(k);
    if (root->val < k)
        root->right = helper(root->right, k);
    else
        root->left = helper(root->left, k);
    return root;
}

TreeNode *inOrder(vector<int> pre, int size)
{
    if (size == 0)
        return NULL;
    TreeNode *root = new TreeNode(pre[0]);
    for (int i = 1; i < size; i++)
        helper(root, pre[i]);
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

    vector<int> preorder = {8, 5, 1, 7, 10, 12};
    int size = 6;

    TreeNode *ans = inOrder(preorder, size);
    cout << ans->val << endl;

    return 0;
}