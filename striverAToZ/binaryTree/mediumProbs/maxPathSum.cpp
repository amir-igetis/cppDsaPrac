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

int helper(TreeNode *root, vector<int> &maxVal)
{
    if (!root)
        return 0;
    int lh = max(0, helper(root->left, maxVal));
    int rh = max(0, helper(root->right, maxVal));

    maxVal[0] = max(maxVal[0], lh + rh + root->val);
    return max(lh, rh) + root->val;
}

int maxPahtSum(TreeNode *root)
{
    vector<int> maxVal = {INT_MIN};
    helper(root, maxVal);
    return maxVal[0];
}

int main()
{

    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(17);
    root->right->right->left = new TreeNode(12);

    cout << maxPahtSum(root) << endl;

    return 0;
}