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

class Solution
{
    int count = 0;

    pair<int, int> postOrder(TreeNode *root)
    {
        if (root == NULL)
        {
            return {0, 0};
        }

        // First iterate over left and right subtrees.
        pair<int, int> left = postOrder(root->left);
        pair<int, int> right = postOrder(root->right);

        int nodeSum = left.first + right.first + root->val;
        int nodeCount = left.second + right.second + 1;

        // Check if the average of the subtree is equal to the node value.
        if (root->val == nodeSum / (nodeCount))
        {
            count++;
        }

        // Return the sum of nodes and the count in the subtree.
        return {nodeSum, nodeCount};
    }

public:
    int averageOfSubtree(TreeNode *root)
    {
        postOrder(root);
        return count;
    }
};

int main()
{

    TreeNode *head = new TreeNode(4);
    head->left = new TreeNode(8);
    head->left->left = new TreeNode(0);
    head->left->right = new TreeNode(1);
    head->right = new TreeNode(5);
    head->right->right = new TreeNode(6);

    Solution sol;
    cout << sol.averageOfSubtree(head) << endl;

    return 0;
}