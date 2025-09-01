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

int sumNumbersI(TreeNode *root)
{
    if (!root)
        return 0;

    int sum = 0;
    stack<TreeNode *> nodeSt;
    stack<int> numSt;

    nodeSt.push(root);
    numSt.push(root->val);
    while (!nodeSt.empty())
    {
        TreeNode *node = nodeSt.top();
        nodeSt.pop();
        int currNum = numSt.top();
        numSt.pop();

        if (!node->left && !node->right)
        {
            sum += currNum;
        }

        if (node->right)
        {
            nodeSt.push(node->right);
            numSt.push(currNum * 10 + node->right->val);
        }

        if (node->left)
        {
            nodeSt.push(node->left);
            numSt.push(currNum * 10 + node->left->val);
        }
    }
    return sum;
}

int dfsHelper(TreeNode *node, int currSum)
{
    if (!node)
        return 0;
    currSum = currSum * 10 + node->val;

    if (!node->left && !node->right)
        return currSum;

    return dfsHelper(node->left, currSum) + dfsHelper(node->right, currSum);
}

int sumNumbers(TreeNode *root)
{
    return dfsHelper(root, 0);
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

    int ans = sumNumbers(root);
    cout<<ans <<endl;

    return 0;
}