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

bool getPath(TreeNode *root, vector<int> &path, int target)
{
    if (root == nullptr)
        return false;

    // add current node
    path.push_back(root->val);

    // target found
    if (root->val == target)
        return true;

    // search left or right
    if (getPath(root->left, path, target) ||
        getPath(root->right, path, target))
        return true;

    // backtrack
    path.pop_back();
    return false;
}

vector<int> solve(TreeNode *root, int target)
{
    vector<int> path;
    if (root == nullptr)
        return path;

    getPath(root, path, target);
    return path;
}

/// this is different

// soln for
// https://practice.geeksforgeeks.org/problems/root-to-leaf-paths/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=root-to-leaf-paths

void leafPaths(TreeNode *root, vector<int> &path,
               vector<vector<int>> &ans)
{
    if (root == nullptr)
        return;

    path.push_back(root->val);

    // leaf node
    if (root->left == nullptr && root->right == nullptr)
    {
        ans.push_back(path);
    }
    else
    {
        leafPaths(root->left, path, ans);
        leafPaths(root->right, path, ans);
    }

    // backtrack
    path.pop_back();
}

vector<vector<int>> Paths(TreeNode *root)
{
    vector<vector<int>> ans;
    vector<int> path;
    leafPaths(root, path, ans);
    return ans;
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

    // root to leaf paths
    vector<vector<int>> allPaths = Paths(root);
    cout << "Root to Leaf Paths:\n";
    for (auto &p : allPaths)
    {
        for (int x : p)
            cout << x << " ";
        cout << endl;
    }

    cout << endl;

    // Root to Node path
    int target = 10;
    vector<int> path = solve(root, target);

    cout << "Path from root to node " << target << ": ";
    for (int i = 0; i < path.size(); i++)
    {
        cout << path[i];
        if (i < path.size() - 1)
            cout << " -> ";
    }
    cout << endl;

    return 0;
}