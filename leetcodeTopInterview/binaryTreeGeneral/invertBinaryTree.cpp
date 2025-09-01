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

TreeNode *invertTree(TreeNode *root)
{
    if (!root)
        return NULL;

    TreeNode *dummy = root->left;
    root->left = invertTree(root->right);
    root->right = invertTree(dummy);

    return root;
}

void printList(TreeNode *root)
{
    if (!root)
        return;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();
        cout << node->val << " ";
        if (node->left)
            q.push(node->left);
        if (node->right)
            q.push(node->right);
    }
    cout << endl;
}

TreeNode *invertTreeI(TreeNode *root)
{

    if (!root)
        return NULL;
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();
        swap(node->left, node->right);
        if (node->left)
            q.push(node->left);
        if (node->right)
            q.push(node->right);
    }

    return root;
}

int main()
{

    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);

    cout << "Original Tree: ";
    printList(root);

    TreeNode *ans = invertTreeI(root);

    cout << "Inverted Tree: ";
    printList(ans);

    return 0;
}