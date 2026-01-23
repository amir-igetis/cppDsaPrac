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

vector<int> getInorder(TreeNode *root)
{
    vector<int> inorder;
    TreeNode *curr = root;
    while (curr)
    {
        if (!curr->left)
        {
            inorder.push_back(curr->val);
            curr = curr->right;
        }
        else
        {
            TreeNode *prev = curr->left;
            while (prev->right && prev->right != curr)
                prev = prev->right;

            if (!prev->right)
            {
                prev->right = curr;
                curr = curr->left;
            }
            else
            {
                prev->right = nullptr;
                inorder.push_back(curr->val);
                curr = curr->right;
            }
        }
    }
    return inorder;
}

int main()
{

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    // root->left->left = new TreeNode(4);
    // root->left->right = new TreeNode(10);
    // root->left->left->right = new TreeNode(5);
    // root->left->left->right->right = new TreeNode(6);
    root->right = new TreeNode(3);
    // root->right->left = new TreeNode(9);
    // root->right->right = new TreeNode(10);

    vector<int> ans = getInorder(root);
    for (auto &i : ans)
        cout << i << " ";
    cout << endl;

    return 0;
}