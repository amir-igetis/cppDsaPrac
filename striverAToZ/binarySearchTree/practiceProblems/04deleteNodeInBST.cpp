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

TreeNode *findLastRight(TreeNode *root)
{
    if (!root->right)
        return root;
    return findLastRight(root->right);
}

TreeNode *helper(TreeNode *root)
{
    if (!root->left)
        return root->right;
    else if (!root->right)
        return root->left;

    TreeNode *rightChild = root->right;
    TreeNode *lastRight = findLastRight(root->left);
    lastRight->right = rightChild;
    return root->left;
}

TreeNode *deleteNode(TreeNode *root, int key)
{
    if (!root)
        return nullptr;
    if (root->val == key)
        return helper(root);

    TreeNode *dummy = root;
    while (root)
    {
        if (root->val > key)
        {
            if (root->left && root->left->val == key)
            {
                root->left = helper(root->left);
                break;
            }
            else
            {
                root = root->left;
            }
        }
        else
        {
            if (root->right && root->right->val == key)
            {
                root->right = helper(root->right);
                break;
            }
            else
            {
                root = root->right;
            }
        }
    }
    return dummy;
}

//    another soln

// soln for https://leetcode.com/problems/delete-node-in-a-bst/
// soln for
// https://practice.geeksforgeeks.org/problems/delete-a-node-from-bst/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=delete-a-node-from-bst

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

    TreeNode *ans = deleteNode(root, 9);

    return 0;
}