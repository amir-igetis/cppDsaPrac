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

bool isLeaf(TreeNode *root)
{
    return !root->left && !root->right;
}

// Function to add the
// left boundary of the tree
void addLeftBoundary(TreeNode *root, vector<int> &res)
{
    TreeNode *curr = root->left;
    while (curr)
    {
        // If the current node is not a leaf,
        // add its value to the result
        if (!isLeaf(curr))
        {
            res.push_back(curr->val);
        }
        // Move to the left child if it exists,
        // otherwise move to the right child
        if (curr->left)
        {
            curr = curr->left;
        }
        else
        {
            curr = curr->right;
        }
    }
}

// Function to add the
// right boundary of the tree
void addRightBoundary(TreeNode *root, vector<int> &res)
{
    TreeNode *curr = root->right;
    vector<int> temp;
    while (curr)
    {
        // If the current node is not a leaf,
        // add its value to a temporary vector
        if (!isLeaf(curr))
        {
            temp.push_back(curr->val);
        }
        // Move to the right child if it exists,
        // otherwise move to the left child
        if (curr->right)
        {
            curr = curr->right;
        }
        else
        {
            curr = curr->left;
        }
    }
    // Reverse and add the values from
    // the temporary vector to the result
    for (int i = temp.size() - 1; i >= 0; --i)
    {
        res.push_back(temp[i]);
    }
}

// Function to add the
// leaves of the tree
void addLeaves(TreeNode *root, vector<int> &res)
{
    // If the current node is a
    // leaf, add its value to the result
    if (isLeaf(root))
    {
        res.push_back(root->val);
        return;
    }
    // Recursively add leaves of
    // the left and right subtrees
    if (root->left)
    {
        addLeaves(root->left, res);
    }
    if (root->right)
    {
        addLeaves(root->right, res);
    }
}

// Main function to perform the
// boundary traversal of the binary tree
vector<int> printBoundary(TreeNode *root)
{
    vector<int> res;
    if (!root)
    {
        return res;
    }
    // If the root is not a leaf,
    // add its value to the result
    if (!isLeaf(root))
    {
        res.push_back(root->val);
    }

    // Add the left boundary, leaves,
    // and right boundary in order
    addLeftBoundary(root, res);
    addLeaves(root, res);
    addRightBoundary(root, res);

    return res;
}

// Helper function to
// print the result
void printResult(const vector<int> &result)
{
    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;
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

    vector<int> ans = printBoundary(root);

    for (auto &j : ans)
        cout << j << " ";
    cout << endl;

    return 0;
}
