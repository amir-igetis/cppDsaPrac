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

bool getpath(TreeNode *root, vector<int> &arr, int x)
{
    if (!root)
        return false;
    arr.push_back(root->val);

    if (root->val == x)
        return true;

    if (getpath(root->left, arr, x) || getpath(root->right, arr, x))
        return true;

    arr.pop_back();
    return false;
}

vector<int> rootToNode(TreeNode *node, int target)
{
    vector<int> arr;
    if (!node)
        return arr;

    getpath(node, arr, target);
    return arr;
}

// gfg solution

void findPaths(TreeNode *root, vector<vector<int>> &res, vector<int> &arr)
{
    if (!root)
        return;

    arr.push_back(root->val);
    if (!root->left && !root->right)
    {
        res.push_back(arr);
    }

    findPaths(root->left, res, arr);
    findPaths(root->right, res, arr);
    arr.pop_back();
}

vector<vector<int>> paths(TreeNode *root)
{
    vector<vector<int>> res;
    vector<int> arr;
    findPaths(root, res, arr);
    return res;
}

int main()
{
    // Constructing the binary tree
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    int target = 7;

    // Get all root-to-leaf paths
    vector<vector<int>> resI = paths(root);

    // Print the result paths
    for (const auto &i : resI)
    {
        for (int it : i)
        {
            cout << it << " "; // Print each value in the path
        }
        cout << endl; // New line after each path
    }

    // Print the number of paths
    cout << "Number of paths: " << resI.size() << endl;

    return 0;
}