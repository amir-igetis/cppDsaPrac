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

int height(TreeNode *root, vector<int> &diameter)
{
    if (!root)
        return 0;
    int left = height(root->left, diameter);
    int right = height(root->right, diameter);
    diameter[0] = max(diameter[0], left + right);
    return 1 + max(left, right);
}

int diameterRecur(TreeNode *root)
{
    vector<int> diameter = {0};
    height(root, diameter);
    return diameter[0];
}

int main()
{

    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(17);

    cout << diameterRecur(root) << endl;

    return 0;
}