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

void helper(TreeNode *root, vector<int> &ans)
{
    if (!root)
        return;
    helper(root->left, ans);
    ans.push_back(root->val);
    helper(root->right, ans);
}

// brute force approach tc and sc O((n + m) * log(n + m)) and O(n + m)
vector<int> merge(TreeNode *p, TreeNode *q)
{
    vector<int> ans;
    helper(p, ans);
    helper(q, ans);
    sort(ans.begin(), ans.end());
    return ans;
}

// optimal approach tc and sc O(n + m)
void helperI(TreeNode *root, vector<int> &ans)
{
    if (!root)
        return;
    helperI(root->left, ans);
    ans.push_back(root->val);
    helperI(root->right, ans);
}

vector<int> mergeArr(vector<int> &arr, vector<int> &arrI)
{
    vector<int> ans;
    int i = 0, j = 0;
    while (i < arr.size() && arrI.size())
    {
        if (arr[i] < arrI[j])
            ans.push_back(arr[i++]);
        else
            ans.push_back(arrI[j++]);
    }
    while (i < arr.size())
        ans.push_back(arr[i++]);
    while (j < arrI.size())
        ans.push_back(arrI[j++]);

    return ans;
}

vector<int> mergeI(TreeNode *p, TreeNode *q)
{
    vector<int> arr, arrI;
    helper(p, arr);
    helper(q, arrI);
    return mergeArr(arr, arrI);
}

void printList(TreeNode *root)
{
    if (!root)
        return;
    printList(root->left);
    cout << root->val << " ";
    printList(root->right);
}

int main()
{

    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(8);
    root->right = new TreeNode(15);
    root->right->right = new TreeNode(17);
    TreeNode *rootI = new TreeNode(12);
    rootI->left = new TreeNode(9);

    vector<int> ans = merge(root, rootI);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << endl;

    vector<int> ansI = mergeI(root, rootI);
    for (auto &i : ansI)
        cout << i << " ";
    cout << endl;

    printList(root);

    return 0;
}