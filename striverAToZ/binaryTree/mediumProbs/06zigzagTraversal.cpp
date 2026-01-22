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

vector<vector<int>> zigZagTrav(TreeNode *root)
{
    vector<vector<int>> arr;
    if (!root)
        return arr;

    queue<TreeNode *> q;
    q.push(root);
    bool leftToRight = true;

    while (!q.empty())
    {
        int size = q.size();
        vector<int> level;

        for (int i = 0; i < size; i++)
        {
            TreeNode *node = q.front();
            q.pop();

            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);

            level.push_back(node->val);
        }

        // Reverse the level if needed
        if (!leftToRight)
        {
            vector<int> reversedLevel;
            for (int i = level.size() - 1; i >= 0; i--)
            {
                reversedLevel.push_back(level[i]);
            }
            arr.push_back(reversedLevel);
        }
        else
        {
            arr.push_back(level);
        }

        leftToRight = !leftToRight;
    }
    return arr;
}

// another way
vector<int> zigZagLevelOrderII(TreeNode *root)
{
    vector<int> wrapList;
    if (!root)
        return wrapList;

    queue<TreeNode *> q;
    q.push(root);
    bool leftToRight = true;

    while (!q.empty())
    {
        int levelNum = q.size();
        vector<int> level(levelNum);

        for (int i = 0; i < levelNum; i++)
        {
            TreeNode *temp = q.front();
            q.pop();

            // Find position to fill node's value
            int index = leftToRight ? i : (levelNum - 1 - i);
            level[index] = temp->val;

            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }

        // Add level to result
        for (int val : level)
        {
            wrapList.push_back(val);
        }

        leftToRight = !leftToRight;
    }
    return wrapList;
}

// soln for https://practice.geeksforgeeks.org/problems/zigzag-tree-traversal/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=zigzag-tree-traversal

vector<int> zigZagLevelOrder(TreeNode *root)
{
    vector<int> result;
    if (!root)
        return result;

    queue<TreeNode *> q;
    q.push(root);
    bool leftToRight = true;

    while (!q.empty())
    {
        int size = q.size();
        vector<int> level;

        for (int i = 0; i < size; i++)
        {
            TreeNode *node = q.front();
            q.pop();
            level.push_back(node->val);

            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }

        // Reverse if needed
        if (!leftToRight)
        {
            reverse(level.begin(), level.end());
        }

        // Add to result
        for (int val : level)
        {
            result.push_back(val);
        }

        leftToRight = !leftToRight;
    }
    return result;
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

    // vector<vector<int>> ans = zigZagTrav(root);
    // vector<int> ans = zigZagLevelOrder(root);
    vector<int> ans = zigZagLevelOrderII(root);

    // for (auto &i : ans)
    // {
    //     for (auto &j : i)
    //         cout << j << " ";
    //     cout << endl;
    // }
    for (auto &i : ans)
        cout << i << " ";
    cout << endl;

    return 0;
}