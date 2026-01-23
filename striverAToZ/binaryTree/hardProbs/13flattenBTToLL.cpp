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

// flatten tree to right-skewed linked list (preorder sequence)
void flattenUtil(TreeNode *root, TreeNode *&prev)
{
    // return if node is null
    if (root == nullptr)
        return;
    // flatten right subtree first
    flattenUtil(root->right, prev);
    // flatten left subtree next
    flattenUtil(root->left, prev);
    // connect current node's right to previously processed node
    root->right = prev;
    // nullify left pointer
    root->left = nullptr;
    // update previous to current
    prev = root;
}

// tc O(n), sc O(log2N)
void flatten(TreeNode *root)
{
    TreeNode *prev = nullptr;
    flattenUtil(root, prev);
}

// better approach  tc O(n), sc O(log2N)

// flatten binary tree to right-skewed linked list (iterative)
void flattenI(TreeNode *root)
{
    TreeNode *prev = nullptr;
    // handle empty tree
    if (!root)
        return;
    // create stack for DFS
    stack<TreeNode *> st;
    // push root to start traversal
    st.push(root);
    // process while stack has nodes
    while (!st.empty())
    {
        // take top node
        TreeNode *cur = st.top();
        // pop it
        st.pop();
        // push right child first (so left is processed first)
        if (cur->right != nullptr)
            st.push(cur->right);
        // push left child next
        if (cur->left != nullptr)
            st.push(cur->left);
        // if stack not empty, link current's right to next node
        if (!st.empty())
            cur->right = st.top();
        // nullify left to form right-only chain
        cur->left = nullptr;
    }
}

// optimal approach tc O(2n) and sc O(1)
void flattenII(TreeNode *root)
{
    // Initialize a pointer
    // 'curr' to the root of the tree
    TreeNode *curr = root;

    while (curr)
    {
        // Check if the current
        // node has a left child
        if (curr->left)
        {
            TreeNode *pre = curr->left;
            while (pre->right)
            {
                pre = pre->right;
            }
            pre->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }
        curr = curr->right;
    }
}

// print preorder traversal
void printPreorder(TreeNode *root)
{
    if (!root)
        return;
    cout << root->val << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

// print nodes following right pointers
void printFlattenTree(TreeNode *root)
{
    if (!root)
        return;
    cout << root->val << " ";
    printFlattenTree(root->right);
}

int main()
{

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->right = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->right->left = new TreeNode(8);

    // print original tree preorder
    cout << "Binary Tree Preorder: ";
    printPreorder(root);
    cout << endl;

    // flatten the tree
    flattenII(root);

    // print flattened tree via right pointers
    cout << "Binary Tree After Flatten: ";
    printFlattenTree(root);
    cout << endl;

    return 0;
}