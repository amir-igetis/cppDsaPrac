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

class SolutionI
{
public:
    int ans = INT_MAX;
    int count = 0;
    void inorder(TreeNode *root, int k)
    {
        if (!root)
            return;
        inorder(root->right, k);
        count++;
        if (count == k)
        {
            ans = root->val;
            return;
        }
        inorder(root->left, k);
    }
    int kthLargest(TreeNode *root, int k)
    {
        inorder(root, k);
        if (ans == INT_MAX)
            return -1;

        return ans;
    }
};

class Solution
{
public:
    int ans = INT_MIN;
    int count = 0;

    void inorder(TreeNode *root, int k)
    {
        if (!root)
            return;
        inorder(root->left, k);
        count++;
        if (count == k)
        {
            ans = root->val;
            return;
        }
        inorder(root->right, k);
    }

    int kthSmallest(TreeNode *root, int k)
    {
        inorder(root, k);
        if (ans == INT_MIN)
            return -1;

        return ans;
    }
};

void printList(TreeNode *root)
{
    if (!root)
        return;
    printList(root->left);
    cout << root->val << " ";
    printList(root->right);
}

// iterative solution O(h)
int kthSmallestI(TreeNode *root, int k)
{
    stack<TreeNode *> st;
    TreeNode *curr = root;
    while (curr || !st.empty())
    {
        while (curr)
        {
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top();
        st.pop();
        k--;
        if (k == 0)
            return curr->val;

        curr = curr->right;
    }
    return -1;
}

// iterative O(h)
int kthLargestI(TreeNode *root, int k)
{
    stack<TreeNode *> st;
    TreeNode *curr = root;
    while (curr || !st.empty())
    {
        while (curr)
        {
            st.push(curr);
            curr = curr->right;
        }
        curr = st.top();
        st.pop();
        k--;
        if (k == 0)
            return curr->val;

        curr = curr->left;
    }
    return -1;
}

int main()
{

    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(8);
    root->right = new TreeNode(15);
    root->right->right = new TreeNode(17);

    Solution sol;
    cout << sol.kthSmallest(root, 1) << endl;

    SolutionI solI;
    cout << solI.kthLargest(root, 2) << endl;

    cout << kthSmallestI(root, 1) << endl;
    cout << kthLargestI(root, 2) << endl;

    return 0;
}