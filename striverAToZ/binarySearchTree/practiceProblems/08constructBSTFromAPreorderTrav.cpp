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

TreeNode *constructPre(vector<int> &pre, int size)
{
    if (size == 0)
        return nullptr;
    TreeNode *root = new TreeNode(pre[0]);
    for (int i = 0; i < size; i++)
        helper(root, pre[i]);

    return root;
}

void printList(TreeNode *root)
{
    if (!root)
        return;
    printList(root->left);
    cout << root->val << " ";
    printList(root->right);
}

int main()
{

    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(8);
    root->right = new TreeNode(15);
    root->right->right = new TreeNode(17);

    vector<int> pre = {10, 5, 1, 8, 15, 17};
    int size = pre.size();

    cout << constructPre(pre, size)->val << endl;
    printList(root);

    return 0;
}