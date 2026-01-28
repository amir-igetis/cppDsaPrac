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

bool isBSTTrav(vector<int> &nums)
{
    int maxi = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        if (maxi >= nums[i])
            return false;
        maxi = nums[i];
    }
    return true;
}

int maxVal(TreeNode *root)
{
    if (!root)
        return -1;
    if (root->right)
        return maxVal(root->right);
    return root->val;
}

int minVal(TreeNode *root)
{
    if (!root)
        return -1;
    if (root->left)
        return minVal(root->left);
    return root->val;
}

int main()
{
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(8);
    root->right = new TreeNode(15);
    root->right->right = new TreeNode(17);

    cout << minVal(root) << endl;

    vector<int> nums = {8, 14, 45, 64, 100};
    cout << (isBSTTrav(nums) ? "TRUE" : "FALSE") << endl;

    return 0;
}