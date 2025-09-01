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

void printInorder(TreeNode *root)
{
    if (!root)
    {
        return;
    }
    cout << root->val << endl;
    printInorder(root->left);
    printInorder(root->right);
}

int leftPred(TreeNode *root)
{
    int predVal = root->val;
    while (!root->left)
    {
        predVal = root->left->val;
        root = root->left;
    }
    return predVal;
}

TreeNode *delNode(TreeNode *root, int key)
{
    if (!root)
        return root;
    ;
    if (root->val > key)
    {
        root->left = delNode(root->left, key);
    }
    if (root->val < key)
    {
        root->right = delNode(root->right, key);
    }
    else
    {
        if (!root->left)
            return root->right;
        else if (!root->right)
            return root->left;

        root->val = leftPred(root->right);
        root->right = delNode(root->right, root->val);
    }
}

int main()
{
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right = new TreeNode(7);

    int key = 4;

    delNode(root, key);
    printInorder(root);

    return 0;
}