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

void mapParentNodes(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &mp)
{
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();
        if (node->left)
        {
            mp[node->left] = node;
            q.push(node->left);
        }
        if (node->right)
        {
            mp[node->right] = node;
            q.push(node->right);
        }
    }
}

vector<int> bfsFromTarget(TreeNode *target, unordered_map<TreeNode *, TreeNode *> &mp, int k)
{
    queue<TreeNode *> q;
    unordered_set<TreeNode *> vis;
    q.push(target);
    vis.insert(target);
    int currLvl = 0;
    while (!q.empty())
    {
        int size = q.size();
        if (currLvl++ == k)
            break;
        for (int i = 0; i < size; i++)
        {
            TreeNode *node = q.front();
            q.pop();
            if (node->left && vis.find(node->left) == vis.end())
            {
                vis.insert(node->left);
                q.push(node->left);
            }
            if (node->right && vis.find(node->right) == vis.end())
            {
                vis.insert(node->right);
                q.push(node->right);
            }
            if (mp.count(node) && vis.find(mp[node]) == vis.end())
            {
                vis.insert(mp[node]);
                q.push(mp[node]);
            }
        }
    }
    vector<int> res;
    while (!q.empty())
    {
        res.push_back(q.front()->val);
        q.pop();
    }
    return res;
}

vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
{
    if (!root)
        return {};
    unordered_map<TreeNode *, TreeNode *> mp;
    mapParentNodes(root, mp);
    return bfsFromTarget(target, mp, k);
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

    vector<int> ans = distanceK(root, root->left, 3);
    for (auto &i : ans)
        cout << i << " ";
    cout << endl;

    return 0;
}