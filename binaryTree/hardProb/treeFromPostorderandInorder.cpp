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

TreeNode *buildTree(vector<int> &inorder, int is, int ie,
                    vector<int> &postorder, int ps, int pe, map<int, int> &mp)
{
    if (is > ie || ps > pe)
        return NULL;
    TreeNode *root = new TreeNode(postorder[pe]);
    int inRoot = mp[postorder[pe]];
    int numsLeft = inRoot - is;
    root->left = buildTree(inorder, is, inRoot - 1,
                           postorder, ps, ps + numsLeft - 1, mp);
    root->right = buildTree(inorder, inRoot + 1, ie,
                            postorder, ps + numsLeft, pe - 1, mp);

    return root;
}

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
{
    map<int, int> mp;
    for (int i = 0; i < inorder.size(); i++)
    {
        mp[inorder[i]] = i;
    }
    TreeNode *root = buildTree(inorder, 0, inorder.size() - 1,
                               postorder, 0, postorder.size() - 1, mp);

    return root;
}

int main()
{
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};
    cout << buildTree(inorder, postorder) << endl;
}