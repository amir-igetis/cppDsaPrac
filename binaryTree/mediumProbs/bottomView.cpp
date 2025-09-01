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

vector<int> bottomView(TreeNode *root)
{
    vector<int> ans;
    map<int, int> mp;
    queue<pair<TreeNode *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        auto it = q.front();
        int col = it.second;
        TreeNode *curr = it.first;
        q.pop();
        mp[col] = curr->val;
        if (curr->left)
            q.push({curr->left, col - 1});
        if (curr->right)
            q.push({curr->right, col + 1});
    }
    for (auto it : mp)
        ans.push_back(it.second);
    return ans;
}

int main()
{
    struct TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    vector<int> res =
        bottomView(root);
    for (auto i : res)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}