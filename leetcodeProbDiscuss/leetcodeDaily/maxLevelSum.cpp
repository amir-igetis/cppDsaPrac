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

// using BFS

int maxLevelSumI(TreeNode *root)
{
    int maxSum = INT_MIN;
    int ans = 0, level = 0;

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        level++;
        int sumAtCurrentLevel = 0;
        // Iterate over all the nodes in the current level.
        for (int sz = q.size(); sz > 0; --sz)
        {
            TreeNode *node = q.front();
            q.pop();
            sumAtCurrentLevel += node->val;

            if (node->left != nullptr)
            {
                q.push(node->left);
            }
            if (node->right != nullptr)
            {
                q.push(node->right);
            }
        }

        if (maxSum < sumAtCurrentLevel)
        {
            maxSum = sumAtCurrentLevel;
            ans = level;
        }
    }

    return ans;
}

// using DFS

void dfs(TreeNode *node, int level, vector<int> &sumOfNodesAtLevel)
{
    if (node == nullptr)
    {
        return;
    }

    if (sumOfNodesAtLevel.size() == level)
    {
        sumOfNodesAtLevel.push_back(node->val);
    }
    else
    {
        sumOfNodesAtLevel[level] += node->val;
    }

    dfs(node->left, level + 1, sumOfNodesAtLevel);
    dfs(node->right, level + 1, sumOfNodesAtLevel);
}

int maxLevelSum(TreeNode *root)
{
    vector<int> sumOfNodesAtLevel;
    dfs(root, 0, sumOfNodesAtLevel);

    int maxSum = INT_MIN;
    int ans = 0;

    for (int i = 0; i < sumOfNodesAtLevel.size(); i++)
    {
        if (maxSum < sumOfNodesAtLevel[i])
        {
            maxSum = sumOfNodesAtLevel[i];
            ans = i + 1;
        }
    }

    return ans;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(7);
    root->left->left = new TreeNode(7);
    root->left->right = new TreeNode(-8);
    root->right = new TreeNode(0);

    cout << maxLevelSum(root) << endl;
    return 0;
}