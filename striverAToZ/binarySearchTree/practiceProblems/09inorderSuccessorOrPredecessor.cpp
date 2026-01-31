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

TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p)
{
    TreeNode *succ = nullptr;
    while (root)
    {
        if (p->val >= root->val)
        {
            root = root->right;
        }
        else
        {
            succ = root;
            root = root->left;
        }
    }
    return succ;
}

TreeNode *inorderSuccessorI(TreeNode *root, TreeNode *p)
{
    TreeNode *succ = nullptr;

    while (root)
    {
        if (p->val < root->val)
        {
            succ = root;
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return succ;
}

TreeNode *inorderPredecessor(TreeNode *root, int p)
{
    TreeNode *pre = nullptr;
    while (root)
    {
        if (root->val >= p)
        {
            root = root->right;
        }
        else
        {
            pre = root;
            root = root->right;
        }
    }
    return pre;
}

TreeNode *inorderPredecessorI(TreeNode *root, TreeNode *p)
{
    TreeNode *pre = nullptr;

    while (root)
    {
        if (p->val > root->val)
        {
            pre = root;
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }
    return pre;
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

    cout << inorderSuccessor(root, root->right)->val << endl;
    printList(root);

    return 0;
}