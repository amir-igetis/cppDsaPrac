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

int countI = 0;
int res = 0;

void inorder(TreeNode *root, int k)
{
    if (!root)
        return;
    inorder(root->left, k);
    countI++;
    if (countI == k)
    {
        res = root->val;
        return;
    }
    inorder(root->right, k);
}

int kthSmallestI(TreeNode *root, int k)
{
    inorder(root, k);
    return res;
}

int kthSmallest(TreeNode *root, int k)
{
    stack<TreeNode *> st;
    TreeNode *curr = root;
    int count = 0;

    while (curr || !st.empty())
    {
        while (curr)
        {
            st.push(curr);
            curr = curr->left;
        }

        curr = st.top();
        st.pop();
        count++;
        if (count == k)
            return curr->val;

        curr = curr->right;
    }
    return -1;
}

int main()
{

    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);

    // root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(2);

    int k = 1;

    cout << kthSmallest(root, k) << endl;

    return 0;
}