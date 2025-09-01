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

TreeNode *kthLargest(TreeNode *root, vector<int> k)
{
    if (!root)
        return NULL;
    TreeNode *right = kthLargest(root->right, k);
    if (!right)
        return right;
    k[0]--;
    if (k[0] == 0)
        return root;

    return kthLargest(root->left, k);
}

TreeNode *kthSmallest(TreeNode *root, vector<int> k)
{
    if (!root)
        return NULL;
    TreeNode *left = kthSmallest(root->left, k);
    if (!left)
        return left;
    k[0]--;
    if (k[0] == 0)
        return root;

    return kthSmallest(root->right, k);
}

// leetcode

void inOrder(TreeNode *node, int &count, int k, int &result)
{
    if (!node || count >= k)
        return;
    inOrder(node->left, count, k, result);
    count++;
    if (count == k)
    {
        result = node->val;
        return;
    }
    inOrder(node->right, count, k, result);
}

int kthSmallestI(TreeNode *root, int k)
{
    int count = 0;
    int result = -1;
    inOrder(root, count, k, result);

    return result;
}

int main()
{

    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(10);

    int k = 3;
    cout << "The " << k << "-th smallest value is: " << kthSmallestI(root, k) << endl;

    return 0;
}