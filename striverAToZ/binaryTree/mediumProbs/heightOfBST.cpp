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

int maxDepthRecur(TreeNode *root)
{

    if (!root)
        return 0;
    int left = maxDepthRecur(root->left);
    int right = maxDepthRecur(root->right);
    return max(left, right) + 1;
}

int maxDepthItr(TreeNode *root)
{
    if (!root)
        return 0;
    queue<TreeNode *> q;
    q.push(root);
    int ans = 0;
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode *node = q.front();
            q.pop();
            if (root->left)
                q.push(root->left);
            if (root->right)
                q.push(root->right);
        }
        ans += 1;
    }
    return ans;
}

int main()
{

    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(17);

    cout << maxDepthRecur(root) << endl;

    return 0;
}