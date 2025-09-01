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

unordered_map<int, int> inordMp;
int preIndex = 0;

TreeNode *constructTree(vector<int> preorder, int left, int right)
{
    if (left > right)
        return NULL;

    int rootVal = preorder[preIndex++];
    TreeNode *root = new TreeNode(rootVal);

    int inorderIndex = inordMp[rootVal];

    root->left = constructTree(preorder, left, inorderIndex - 1);
    root->right = constructTree(preorder, inorderIndex + 1, right);

    return root;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    for (int i = 0; i < inorder.size(); i++)
    {
        inordMp[inorder[i]] = i;
    }

    return constructTree(preorder, 0, inorder.size() - 1);
}

void printList(TreeNode *root)
{
    if (!root)
        return;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();
        cout << node->val << " ";
        if (node->left)
            q.push(node->left);
        if (node->right)
            q.push(node->right);
    }
    cout << endl;
}

int main()
{

    // TreeNode *root = new TreeNode(4);
    // root->left = new TreeNode(2);
    // root->right = new TreeNode(2);
    // root->left->left = new TreeNode(3);
    // root->left->right = new TreeNode(4);
    // root->right->left = new TreeNode(4);
    // root->right->right = new TreeNode(3);

    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};
    TreeNode *ans = buildTree(preorder, inorder);
    // cout << "Original Tree: ";
    // printList(root);

    // bool ans = isSymmetric(root);

    // cout << "Inverted Tree: ";
    printList(ans);

    // cout << ans << endl;

    return 0;
}