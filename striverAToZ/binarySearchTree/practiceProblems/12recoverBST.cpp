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

class RecoverBST
{
private:
    // for recursive solution
    TreeNode *first = nullptr;
    TreeNode *middle = nullptr;
    TreeNode *last = nullptr;
    TreeNode *prev = nullptr;

    /* =======================
       Recursive inorder
       ======================= */
    void inorder(TreeNode *root)
    {
        if (root == nullptr)
            return;

        inorder(root->left);

        if (prev != nullptr && root->val < prev->val)
        {
            if (first == nullptr)
            {
                first = prev;
                middle = root;
            }
            else
            {
                last = root;
            }
        }

        prev = root;
        inorder(root->right);
    }

    /* =======================
       Morris helper
       ======================= */
    TreeNode *findPredecessor(TreeNode *root)
    {
        TreeNode *pred = root->left;
        while (pred->right != nullptr && pred->right != root)
            pred = pred->right;
        return pred;
    }

    void swapNodes(TreeNode *x, TreeNode *y)
    {
        int temp = x->val;
        x->val = y->val;
        y->val = temp;
    }

public:
    /* =======================
       GFG: Fix swapped BST
       ======================= */
    TreeNode *correctBST(TreeNode *root)
    {
        first = middle = last = nullptr;
        prev = new TreeNode(INT_MIN);

        inorder(root);

        if (last != nullptr)
            swapNodes(first, last);
        else
            swapNodes(first, middle);

        return root;
    }

    /* =======================
       LeetCode: Morris Traversal
       ======================= */
    void recoverTree(TreeNode *root)
    {
        TreeNode *pred = nullptr;
        TreeNode *x = nullptr;
        TreeNode *y = nullptr;

        while (root != nullptr)
        {
            if (root->left == nullptr)
            {
                if (pred != nullptr && root->val < pred->val)
                {
                    y = root;
                    if (x == nullptr)
                        x = pred;
                }
                pred = root;
                root = root->right;
            }
            else
            {
                TreeNode *morrisPred = findPredecessor(root);

                if (morrisPred->right == nullptr)
                {
                    morrisPred->right = root;
                    root = root->left;
                }
                else
                {
                    if (pred != nullptr && root->val < pred->val)
                    {
                        y = root;
                        if (x == nullptr)
                            x = pred;
                    }
                    pred = root;
                    morrisPred->right = nullptr;
                    root = root->right;
                }
            }
        }
        swapNodes(x, y);
    }
};

/* =======================
   Utility: Inorder print
   ======================= */
void printInorder(TreeNode *root)
{
    if (!root)
        return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main()
{
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(8);
    root->right = new TreeNode(15);
    root->right->right = new TreeNode(17);

    RecoverBST solver;

    cout << "Before fixing BST: ";
    printInorder(root);
    cout << endl;

    solver.correctBST(root); // recursive solution
    // solver.recoverTree(root); // Morris solution

    cout << "After fixing BST: ";
    printInorder(root);
    cout << endl;

    return 0;
}
