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

bool validate(TreeNode *node, long long mini, long long maxi)
{
    if (!node)
        return true;

    if (node->val <= mini || node->val >= maxi)
        return false;

    return validate(node->left, mini, node->val) && validate(node->right, node->val, maxi);
}

bool isValidBST(TreeNode *root)
{
    return validate(root, LLONG_MIN, LLONG_MAX);
}

bool isValidBSTI(TreeNode *root)
{
    stack<TreeNode *> st;
    TreeNode *curr = root;
    long long prev = LLONG_MIN;

    while (curr || !st.empty())
    {
        while (curr)
        {
            st.push(curr);
            curr = curr->left;
        }

        curr = st.top();
        st.pop();
        if (curr->val <= prev)
            return false;

        prev = curr->val;

        curr = curr->right;
    }

    return true;
}
int main()
{

    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);

    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(6);

    cout << isValidBSTI(root) << endl;

    return 0;
}