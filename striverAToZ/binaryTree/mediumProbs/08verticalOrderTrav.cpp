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

vector<vector<int>> findVertical(TreeNode *root)
{
    // A map is used to store nodes grouped by vertical and level
    map<int, map<int, multiset<int>>> nodes;

    // A queue is used for BFS, storing node and its coordinates
    queue<pair<TreeNode *, pair<int, int>>> todo;

    // Push the root node with vertical = 0 and level = 0
    todo.push({root, {0, 0}});

    // Perform BFS traversal
    while (!todo.empty())
    {
        // Get the front element in queue
        auto p = todo.front();
        todo.pop();

        // Extract node
        TreeNode *temp = p.first;
        // Extract vertical (x)
        int x = p.second.first;
        // Extract level (y)
        int y = p.second.second;

        // Insert the node into map by vertical and level
        nodes[x][y].insert(temp->val);

        // If left child exists, push with updated coordinates
        if (temp->left)
        {
            todo.push({temp->left, {x - 1, y + 1}});
        }

        // If right child exists, push with updated coordinates
        if (temp->right)
        {
            todo.push({temp->right, {x + 1, y + 1}});
        }
    }

    // Final answer vector
    vector<vector<int>> ans;

    // Iterate through verticals in map
    for (auto p : nodes)
    {
        vector<int> col;
        // Collect all nodes in order of levels
        for (auto q : p.second)
        {
            col.insert(col.end(), q.second.begin(), q.second.end());
        }
        // Push the column into result
        ans.push_back(col);
    }

    // Return final vertical order traversal
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

    vector<vector<int>> ans = findVertical(root);

    for (auto &i : ans)
    {
        for (auto &j : i)
            cout << j << " ";
        cout << endl;
    }
    cout << endl;

    return 0;
}