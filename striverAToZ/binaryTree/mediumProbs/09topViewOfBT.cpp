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

vector<int> topView(TreeNode *root)
{
    vector<int> ans;
    if (!root)
        return ans;

    // Use map instead of unordered_map to maintain sorted order by horizontal distance
    map<int, int> mp;
    queue<pair<TreeNode *, int>> q;
    q.push({root, 0});

    while (!q.empty())
    {
        TreeNode *temp = q.front().first;
        int line = q.front().second;
        q.pop();

        // Only store the first node at each horizontal distance (top view)
        if (mp.find(line) == mp.end())
            mp[line] = temp->val;

        if (temp->left)
            q.push({temp->left, line - 1});
        if (temp->right)
            q.push({temp->right, line + 1});
    }

    // Extract values in sorted order of horizontal distance
    for (auto &it : mp)
        ans.push_back(it.second);

    return ans;
}

int main()
{

    // TreeNode *root = new TreeNode(5);
    // root->left = new TreeNode(2);
    // root->right = new TreeNode(7);
    // root->left->left = new TreeNode(1);
    // root->left->right = new TreeNode(4);
    // root->right->right = new TreeNode(17);
    // root->right->right->left = new TreeNode(12);

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(10);
    root->left->left->right = new TreeNode(5);
    root->left->left->right->right = new TreeNode(6);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(10);

    vector<int> ans = topView(root);

    for (auto &i : ans)
        cout << i << " ";
    cout << endl;

    return 0;
}