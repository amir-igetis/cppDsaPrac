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

class BSTIterator
{
private:
    void pushLeftNodes(TreeNode *node)
    {
        while (node)
        {
            st.push(node);
            node = node->left;
        }
    }

public:
    stack<TreeNode *> st;
    BSTIterator(TreeNode *root)
    {
        pushLeftNodes(root);
    }

    int next()
    {
        TreeNode *node = st.top();
        st.pop();
        if (node->right)
        {
            pushLeftNodes(node->right);
        }

        return node->val;
    }

    bool hasNext()
    {
        return !st.empty();
    }
};

int main()
{

    return 0;
}