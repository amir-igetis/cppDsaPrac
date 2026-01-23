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

int widthOfBT(TreeNode *root)
{
    if (!root)
        return 0;
    int maxWidth = 0;
    queue<pair<TreeNode *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        int size = q.size();
        int minIdx = q.front().second;
        int first = 0;
        int last = 0;
        for (int i = 0; i < size; i++)
        {
            int currIdx = q.front().second - minIdx;
            TreeNode *node = q.front().first;
            q.pop();
            if (i == 0)
            {
                first = currIdx;
            }
            if (i == size - 1)
                last = currIdx;
            if (node->left)
                q.push({node->left, 2 * currIdx + 1});
            if (node->right)
                q.push({node->right, 2 * currIdx + 2});
        }
        maxWidth = max(maxWidth, last - first + 1);
    }
    return maxWidth;
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

    cout << widthOfBT(root) << endl;

    return 0;
}