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

bool isSymmetricHelper(TreeNode *p, TreeNode *q)
{
    if (!p && !q)
        return true;
    if (!p || !q)
        return false;

    return ((p->val == q->val) &&
            isSymmetricHelper(p->left, q->right) &&
            isSymmetricHelper(p->right, q->left));
}

bool isSymmetric(TreeNode *root)
{
    if (!root)
        return true;

    return isSymmetricHelper(root->left, root->right);
}

bool isSymmetricI(TreeNode *root)
{

    if (!root)
        return true;

    queue<TreeNode *> q;
    q.push(root->left);
    q.push(root->right);

    while (!q.empty())
    {
        TreeNode *left = q.front();
        q.pop();
        TreeNode *right = q.front();
        q.pop();

        if (!left && !right)
            continue;

        if (!left || !right || left->val != right->val)
            return false;

        q.push(left->left);
        q.push(right->right);
        q.push(left->right);
        q.push(left->left);
    }

    return true;
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

    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    cout << "Original Tree: ";
    printList(root);

    bool ans = isSymmetric(root);

    // cout << "Inverted Tree: ";
    // printList(ans);

    cout << ans << endl;

    return 0;
}