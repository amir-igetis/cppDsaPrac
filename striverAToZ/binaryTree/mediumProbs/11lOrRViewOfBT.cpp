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

void leftDFS(TreeNode *node, int level, vector<int> &res)
{
    // Base case: null node
    if (!node)
        return;

    // If this is the first node at the current level
    if (res.size() == level)
        res.push_back(node->val);

    // Explore left subtree first
    leftDFS(node->left, level + 1, res);

    // Then explore right subtree
    leftDFS(node->right, level + 1, res);
}

// Recursive function to get right view
void rightDFS(TreeNode *node, int level, vector<int> &res)
{
    if (!node)
        return;

    if (res.size() == level)
        res.push_back(node->val);

    // Explore right subtree first
    rightDFS(node->right, level + 1, res);

    // Then explore left subtree
    rightDFS(node->left, level + 1, res);
}

// left view code
vector<int> leftView(TreeNode *root)
{
    vector<int> res;
    leftDFS(root, 0, res);
    return res;
}

// right view code
vector<int> rightView(TreeNode *root)
{
    vector<int> res;
    rightDFS(root, 0, res);
    return res;
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

    vector<int> ans = rightView(root);

    for (auto &i : ans)
        cout << i << " ";
    cout << endl;

    vector<int> ansI = leftView(root);
    for (auto &i : ansI)
        cout << i << " ";
    cout << endl;

    return 0;
}