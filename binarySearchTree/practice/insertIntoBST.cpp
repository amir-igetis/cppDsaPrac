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

TreeNode *insert(TreeNode *root, int key)
{
    if (!root)
    {
        root = new TreeNode(key);
        return root;
    }
    if (root->val == key)
        return root;
    if (root->val > key)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);

    return root;
}

// without recursion
TreeNode *insertI(TreeNode *root, int key)
{
    if (!root)
        return new TreeNode(key);
    TreeNode *curr = root;
    while (true)
    {
        if (curr->val <= key)
        {
            if (!curr->right)
                curr = curr->right;
            else
            {
                curr->right = new TreeNode(key);
                break;
            }
        }
        else
        {
            if (!curr->left)
            {
                curr = curr->left;
            }
            else
            {
                curr->left = new TreeNode(key);
                break;
            }
        }
    }
    return root;
}

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

int main()
{
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right = new TreeNode(7);

    int key = 8;
    insert(root, key);

    printInorder(root);

    return 0;
}