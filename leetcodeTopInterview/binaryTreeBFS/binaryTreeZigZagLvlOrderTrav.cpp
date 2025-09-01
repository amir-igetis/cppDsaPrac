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

vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    vector<vector<int>> res;
    if (!root)
        return res;
    queue<TreeNode *> q;
    q.push(root);
    int flag = 1;
    while (!q.empty())
    {
        int size = q.size();
        vector<int> lvl(size);
        for (int i = 0; i < size; i++)
        {
            TreeNode *node = q.front();
            q.pop();
            int index;
            if (flag == 1)
            {
                index = i;
            }
            else
            {
                index = size - 1 - i;
            }
            lvl[index] = node->val;

            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        res.push_back(lvl);
        if (flag == 1)
            flag = 0;
        else
            flag = 1;
    }

    return res;
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

    vector<vector<int>> res = zigzagLevelOrder(root);

    int k = 1;
    for (auto &i : res)
    {

        cout << "This is the " << k << "th level" << endl;

        for (auto &j : i)
        {
            cout << j << ", ";
        }
        cout << endl;
        k++;
    }
    cout << endl;

    // cout << res[res.size() - 1] << endl;

    return 0;
}