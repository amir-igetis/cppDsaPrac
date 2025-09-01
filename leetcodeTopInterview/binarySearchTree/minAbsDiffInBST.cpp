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

int minDiff = INT_MAX;
int prevVal = -1;

void inorder(TreeNode *root)
{
    if (!root)
        return;

    inorder(root->left);
    if (prevVal != -1)
        minDiff = min(minDiff, root->val - prevVal);

    prevVal = root->val;
    inorder(root->right);
}

int getMinimumDifference(TreeNode *root)
{
    inorder(root);
    return minDiff;
}

int getMinimumDifferenceI(TreeNode *root)
{
    stack<TreeNode *> st;
    TreeNode *curr = root;
    int prev = -1;
    int minDiff = INT_MAX;

    while (curr || !st.empty())
    {
        while (curr)
        {
            st.push(curr);
            curr = curr->left;
        }

        curr = st.top();
        st.pop();

        if (prev != -1)
        {
            minDiff = min(minDiff, curr->val - prev);
        }
        prev = curr->val;

        curr = curr->right;
    }

    return minDiff;
}

int main()
{

    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);

    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    cout << getMinimumDifference(root) << endl;

    return 0;
}