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

bool isConstructBST(vector<int> &nums)
{
    int max = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        if (max >= nums[i])
            return false;

        max = nums[i];
    }
    return true;
}

// search elem in bst
bool search(TreeNode *root, int x)
{
    if (!root)
        return false;
    else if (root->val == x)
        return true;
    else if (root->val > x)
        return search(root->left, x);
    else
        return search(root->right, x);
}

// min and max in bst
int minval(TreeNode *root)
{
    if (!root)
        return -1;
    if (!root->left)
        return minval(root->left);
    return root->val;
}

int maxVal(TreeNode *root)
{
    if (!root)
        return -1;
    if (!root->right)
        return maxVal(root->right);
    return root->val;
}

// ceil in bst
int findCeil(TreeNode *root, int x)
{
    int ceil = INT_MIN;
    while (!root)
    {
        if (root->val == x)
        {
            ceil = root->val;
            return ceil;
        }
        if (x > root->val)
            root = root->right;
        else
        {
            ceil = root->val;
            root = root->left;
        }
        return ceil;
    }
}

// floor in bst
int findFloor(TreeNode *root, int x)
{
    int floor = INT_MAX;
    while (!root)
    {
        if (root->val == x)
        {
            floor = root->val;
            return floor;
        }
        if (x < root->val)
            root = root->left;
        else
        {
            floor = root->val;
            root = root->right;
        }
    }
    return floor;
}

int main()
{
    vector<int> nums = {4, 27, 1, 3};
    cout << isConstructBST(nums);

    return 0;
}