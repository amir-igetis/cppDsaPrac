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

void changeTree(TreeNode *root)
{
    if (!root)
        return;
    int child = 0;
    if (root->left)
        child += root->left->val;
    if (root->right)
        child += root->right->val;

    if (child >= root->val)
    {
        root->val = child;
    }
    else
    {
        if (root->left)
            root->left->val = root->val;
        else if (root->right)
            root->right->val = root->val;
    }
    changeTree(root->left);
    changeTree(root->right);
    int tot = 0;
    if (root->left)
        tot += root->left->val;
    if (root->right)
        tot += root->right->val;

    if (root->left || root->right)
        root->val = tot;
}

// soln for
// https://practice.geeksforgeeks.org/problems/children-sum-parent/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=hildren-sum-parent
int isSumPropertyI(TreeNode *root)
{
    // add your code here
    if (!root)
        return 1;
    if (!root->left & !root->right)
    {
        return 1;
    }
    int sum = 0;
    if (root->left)
    {
        sum += root->left->val;
    }
    if (root->right)
    {
        sum += root->right->val;
    }
    if (root->val == sum)
    {
        return (isSumPropertyI(root->left) &
                isSumPropertyI(root->right));
    }
    return 0;
}

void printTree(TreeNode *root)
{
    if (!root)
        return;
    printTree(root->left);
    cout << root->val << " ";
    printTree(root->right);
}

int main()
{

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(10);
    root->left->left->right = new TreeNode(5);
    root->left->left->right->right = new TreeNode(6);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(10);

    cout << "The original tree is -->" << endl;
    printTree(root);
    cout << endl;

    changeTree(root);

    cout << "The modified tree is -->" << endl;
    printTree(root);
    cout << endl;

    cout << isSumPropertyI(root) << endl;

    return 0;
}