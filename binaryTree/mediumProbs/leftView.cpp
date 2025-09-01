#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {};
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {};
};

void rightView(TreeNode *curr, vector<int> &res, int lvl)
{
    if (!curr)
        return;
    if (lvl == res.size())
        res.push_back(curr->val);
    rightView(curr->right, res, lvl + 1);
    rightView(curr->left, res, lvl + 1);
}

vector<int> rightView(TreeNode *root)
{
    vector<int> ans;
    rightView(root, ans, 0);
    return ans;
}

void leftView(TreeNode *curr, vector<int> &res, int lvl)
{
    if (!curr)
    {
        return;
    }
    if (lvl == res.size())
        res.push_back(curr->val);

    leftView(curr->left, res, lvl + 1);
    leftView(curr->right, res, lvl + 1);
}

vector<int> leftView(TreeNode *root)
{
    vector<int> ans;
    leftView(root, ans, 0);
    return ans;
}

int main()
{
    struct TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    vector<int> res = leftView(root);
    for (auto i : res)
    {
        cout << i << " ";
    }
    cout << endl;

    vector<int> resI = rightView(root);
    for (auto i : resI)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}