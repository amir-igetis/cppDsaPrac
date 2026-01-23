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

// Helper method to build an undirected graph from binary tree
void buildGraph(TreeNode *node, TreeNode *parent, unordered_map<int, vector<int>> &graph)
{
    // Base case: if current node is null, return
    if (!node)
        return;

    // If parent exists, add bidirectional connection
    if (parent)
    {
        graph[node->val].push_back(parent->val);
        graph[parent->val].push_back(node->val);
    }

    // Recursively build graph for left and right children
    buildGraph(node->left, node, graph);
    buildGraph(node->right, node, graph);
}

int minTime(TreeNode *root, int target)
{
    unordered_map<int, vector<int>> graph;
    buildGraph(root, nullptr, graph);

    // Use a set to track visited (burned) nodes
    unordered_set<int> visited;

    // Use queue for BFS starting from the target node
    queue<int> q;
    q.push(target);
    visited.insert(target);

    // Track time taken to burn the tree
    int time = 0;

    // Perform level-order BFS to simulate the spread of fire
    while (!q.empty())
    {
        int size = q.size();
        bool burned = false;

        // Process each node at the current level
        for (int i = 0; i < size; i++)
        {
            int node = q.front();
            q.pop();

            // Traverse all adjacent (connected) nodes
            for (int neighbor : graph[node])
            {
                if (!visited.count(neighbor))
                {
                    visited.insert(neighbor);
                    q.push(neighbor);
                    burned = true;
                }
            }
        }

        // If fire spread to new nodes, increment time
        if (burned)
            time++;
    }

    // Return total time taken to burn the tree
    return time;
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

    int k = 9;

    cout << minTime(root, k) << endl;

    return 0;
}