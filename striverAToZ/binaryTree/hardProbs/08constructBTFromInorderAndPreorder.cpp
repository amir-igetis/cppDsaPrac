
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

// Recursive function to build tree using preorder and inorder segments
TreeNode *build(vector<int> &preorder, int preStart, int preEnd,
                vector<int> &inorder, int inStart, int inEnd, map<int, int> &inMap)
{

    // Base condition
    if (preStart > preEnd || inStart > inEnd)
        return nullptr;

    // The first element in preorder is root
    TreeNode *root = new TreeNode(preorder[preStart]);

    // Find the root index in inorder
    int inRoot = inMap[root->val];

    // Number of elements in left subtree
    int numsLeft = inRoot - inStart;

    // Recursively build left and right subtrees
    root->left = build(preorder, preStart + 1, preStart + numsLeft,
                       inorder, inStart, inRoot - 1, inMap);
    root->right = build(preorder, preStart + numsLeft + 1, preEnd,
                        inorder, inRoot + 1, inEnd, inMap);

    return root;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    // Map to store the index of each value in inorder
    map<int, int> inMap;

    // Fill the map with inorder values and their indices
    for (int i = 0; i < inorder.size(); i++)
    {
        inMap[inorder[i]] = i;
    }

    // Call the recursive helper function
    return build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inMap);
}

// using global variable
unordered_map<int, int> mp;
int preIdx = 0;
TreeNode *constructTreeI(vector<int> &preorder, int left, int right)
{
    if (left > right)
        return NULL;
    int rootVal = preorder[preIdx++];
    TreeNode *root = new TreeNode(rootVal);
    int inIdx = mp[rootVal];
    root->left = constructTreeI(preorder, left, inIdx - 1);
    root->right = constructTreeI(preorder, inIdx + 1, right);
    return root;
}

TreeNode *buildTreeI(vector<int> &preorder, vector<int> &inorder)
{
    for (int i = 0; i < inorder.size(); i++)
    {
        mp[inorder[i]] = i;
    }
    return constructTreeI(preorder, 0, inorder.size() - 1);
}

// Inorder traversal to print tree
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

    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> preorder = {3, 9, 20, 15, 7};

    // TreeNode *root = buildTree(preorder, inorder);
    TreeNode *root = buildTreeI(preorder, inorder);

    cout << "Inorder of Unique Binary Tree Created:\n";
    printInorder(root);
    cout << endl;

    return 0;
}
