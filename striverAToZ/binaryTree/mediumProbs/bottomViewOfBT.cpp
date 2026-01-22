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

vector<int> bottomView(TreeNode *root)
{
    // Vector to store the result
    vector<int> ans;

    // Check if the tree is empty
    if (root == NULL)
    {
        return ans;
    }

    // Map to store the bottom view nodes
    // based on their vertical positions
    map<int, int> mpp;

    // Queue for BFS traversal, each
    // element is a pair containing node
    // and its vertical position
    queue<pair<TreeNode *, int>> q;

    // Push the root node with its vertical
    // position (0) into the queue
    q.push({root, 0});

    // BFS traversal
    while (!q.empty())
    {
        // Retrieve the node and its vertical
        // position from the front of the queue
        auto it = q.front();
        q.pop();
        TreeNode *node = it.first;
        int line = it.second;

        // Update the map with the node's data
        // for the current vertical position
        mpp[line] = node->val;

        // Process left child
        if (node->left != NULL)
        {
            // Push the left child with a decreased
            // vertical position into the queue
            q.push({node->left, line - 1});
        }

        // Process right child
        if (node->right != NULL)
        {
            // Push the right child with an increased
            // vertical position into the queue
            q.push({node->right, line + 1});
        }
    }

    // Transfer values from the
    // map to the result vector
    for (auto it : mpp)
    {
        ans.push_back(it.second);
    }

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

    vector<int> ans = bottomView(root);

    for (auto &i : ans)
        cout << i << " ";
    cout << endl;

    return 0;
}