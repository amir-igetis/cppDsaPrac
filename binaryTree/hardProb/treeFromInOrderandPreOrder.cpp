#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {};
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {};
};

TreeNode *buildTree(vector<int> &preorder, int prestart, int preend,
                    vector<int> &inorder, int instart, int inend, map<int, int> &mp)
{
    if (prestart > preend || instart > inend)
        return NULL;

    TreeNode *root = new TreeNode(preorder[prestart]);
    int inRoot = mp[root->val];

    int numsLeft = inRoot - instart;

    root->left = buildTree(preorder, prestart + 1, prestart + numsLeft,
                           inorder, instart, inRoot - 1, mp);
    root->right = buildTree(preorder, prestart + numsLeft + 1, preend,
                            inorder, inRoot + 1, inend, mp);

    return root;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    map<int, int> mp;
    for (int i = 0; i < inorder.size(); i++)
    {
        mp[inorder[i]] = i;
    }

    return buildTree(preorder, 0, preorder.size() - 1,
                     inorder, 0, inorder.size() - 1, mp);
}

int main()
{
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};
    cout << buildTree(preorder, inorder) << endl;
}