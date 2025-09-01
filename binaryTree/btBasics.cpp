#include <bits/stdc++.h>
using namespace std;

// struct TreeNode
// {
//     int data;
//     struct TreeNode *left;
//     struct TreeNode *right;
//     TreeNode(int val)
//     {
//         data = val;
//         left = right = NULL;
//     }
// };

// this is for leetcode
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<int> preorderTraversal(TreeNode *root)
{
    vector<int> ans;
    preorder(root, ans);
    return ans;
}

void preorder(TreeNode *root, vector<int> &arr)
{
    if (!root)
    {
        arr.push_back(root->val);
        preorder(root->left, arr);
        preorder(root->right, arr);
    }
}

vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> ans;
    preorder(root, ans);
    return ans;
}

void inorder(TreeNode *root, vector<int> &arr)
{
    if (!root)
    {
        inorder(root->left, arr);
        arr.push_back(root->val);
        inorder(root->right, arr);
    }
}

vector<int> postorderTraversal(TreeNode *root)
{
    vector<int> ans;
    postorder(root, ans);
    return ans;
}

void postorder(TreeNode *root, vector<int> &arr)
{
    if (!root)
    {
        postorder(root->left, arr);
        postorder(root->right, arr);
        arr.push_back(root->val);
    }
}

// levelorder
vector<int> levelorderTraversal(TreeNode *root)
{
    vector<int> ans;
    if (!root)
    {
        return ans;
    }

    vector<deque<int>> deq;
    queue<TreeNode> que;
    int ele = 0;
    while (!que.empty())
    {
        // deque<int> d;
        // int c = que.size();
        // for (int i = 0; i < c; i++)
        // {
        //     TreeNode curr = que.front();
        //     if (ele == 0)
        //     // d.emplace_front(curr->val);
        // }
    }
    return ans;
}

vector<vector<int>> levelOrderI(TreeNode *root)
{
    queue<TreeNode *> q;
    vector<vector<int>> ans;
    if (!root)
        return ans;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        vector<int> level;
        for (int i = 0; i < size; i++)
        {
            TreeNode *node = q.front();
            q.pop();
            if (node->left != NULL)
                q.push(node->left);
            if (node->right != NULL)
                q.push(node->right);
            level.push_back(node->val);
        }
        ans.push_back(level);
    }
    return ans;
}

int main()
{
    struct TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);

    return 0;
}