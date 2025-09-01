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

void flatten(TreeNode *root)
{
    TreeNode *curr = root;
    while (curr)
    {
        if (curr->left)
        {
            TreeNode *rightMost = curr->left;
            while (rightMost->right)
            {
                rightMost = rightMost->right;
            }
            rightMost->right = curr->right;

            curr->right = curr->left;
            curr->left = NULL;
        }
        curr = curr->right;
    }
}

void printLL(TreeNode *root)
{
    TreeNode *curr = root;
    while (curr)
    {
        cout << curr->val << "->";
        curr = curr->right;
    }
    cout << "NULL";
    cout << endl;
}

int main()
{

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    // root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(6);

    flatten(root);

    printLL(root);

    return 0;
}