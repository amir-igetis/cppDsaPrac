#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    TreeNode *left;
    TreeNode *right;
    int val;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

long long totalSum = 0;
long long maxProd = 0;
const int MOD = 1e9 + 7;

long long getTotalSum(TreeNode *node)
{
    if (!node)
        return 0;
    return node->val + getTotalSum(node->left) + getTotalSum(node->right);
}

long long getSubTreeSum(TreeNode *node)
{
    if (!node)
        return 0;

    long long left = getSubTreeSum(node->left);
    long long right = getSubTreeSum(node->right);

    long long subSum = node->val + left + right;
    maxProd = max(maxProd, subSum * (totalSum - subSum));

    return subSum;
}

int maxProduct(TreeNode *root)
{
    totalSum = 0;
    maxProd = 0;

    totalSum = getTotalSum(root);
    getSubTreeSum(root);

    return maxProd % MOD;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(4);
    root->right->right->left = new TreeNode(5);
    root->right->right->right = new TreeNode(6);

    cout << maxProduct(root) << endl;
    return 0;
}
