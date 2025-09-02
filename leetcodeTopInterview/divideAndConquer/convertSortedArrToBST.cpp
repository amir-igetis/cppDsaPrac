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

TreeNode *constructBST(vector<int> &nums, int left, int right)
{
    if (left > right)
        return NULL;

    int mid = left + (right - left) / 2;
    TreeNode *root = new TreeNode(nums[mid]);
    root->left = constructBST(nums, left, mid - 1);
    root->right = constructBST(nums, mid + 1, right);

    return root;
}

TreeNode *sortedArrayToBST(vector<int> &nums)
{
    return constructBST(nums, 0, nums.size() - 1);
}

void inorder(TreeNode *root)
{
    if (root)
    {
        inorder(root->left);
        cout << root->val << " ";
        inorder(root->right);
    }
}

void lvlprint(TreeNode *root)
{
    if (!root)
        return;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();
        cout << node->val << " ";
        if (node->left)
            q.push(node->left);
        if (node->right)
            q.push(node->right);
    }
}

int main()
{
    vector<int> nums = {-10, -3, 0, 5, 9};
    TreeNode *ans = sortedArrayToBST(nums);
    // inorder(ans);
    lvlprint(ans);

    return 0;
}