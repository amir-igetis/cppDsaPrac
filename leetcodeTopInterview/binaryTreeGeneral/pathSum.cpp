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

void printList(TreeNode *root)
{
    if (!root)
        return;
    TreeNode *curr = root;
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
}

bool hasPathSum(TreeNode *root, int targetSum)
{
    if (!root)
        return false;
    if (!root->left && !root->right && targetSum == root->val)
        return true;

    return hasPathSum(root->left, targetSum - root->val) ||
           hasPathSum(root->right, targetSum - root->val);
}

bool hasPathSumI(TreeNode *root, int targetSum)
{
    if (!root)
        return false;
    stack<TreeNode *> nodeSt;
    stack<int> sumSt;

    nodeSt.push(root);
    sumSt.push(targetSum - root->val);

    while (!nodeSt.empty())
    {
        TreeNode *node = nodeSt.top();
        nodeSt.pop();

        int currSum = sumSt.top();
        sumSt.pop();

        if (!node->left && !node->right && currSum == 0)
            return true;

        if (node->right)
        {
            nodeSt.push(node->right);
            sumSt.push(currSum - node->right->val);
        }

        if (node->left)
        {
            nodeSt.push(node->left);
            sumSt.push(currSum - node->left->val);
        }
    }
    return false;
}

int main()
{
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);

    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);

    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->right = new TreeNode(1);

    int targetSum = 22;

    bool ans = hasPathSum(root, targetSum);
    cout << (ans ? "true" : "false") << endl;

    return 0;
}
