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

void printList(TreeNode *node)
{
    if (!node)
        return;
    printList(node->left);
    cout << node->val;
    printList(node->right);
}

int countNodes(int i)
{
    return (int)(pow(2, i - 1));
}

// create Tree
void createTree(TreeNode *root, vector<int> &v)
{
    queue<TreeNode *> q;
    q.push(root);
    int it = 1;
    int len = v.size();
    while (it < len)
    {
        TreeNode *temp = q.front();
        q.pop();
        TreeNode *leftNode = new TreeNode(v[it]);
        temp->left = leftNode;
        q.push(leftNode);
        it++;
        TreeNode *rightNode = new TreeNode(v[it]);
        temp->right = rightNode;
        q.push(rightNode);
        it++;
    }
}

// preorder iterative
vector<int> preorder(TreeNode *root)
{
    stack<TreeNode *> st;
    vector<int> arr;
    st.push(root);
    while (!st.empty())
    {
        TreeNode *temp = st.top();
        st.pop();
        arr.push_back(temp->val);
        if (temp->right)
            st.push(temp->right);
        if (temp->left)
            st.push(temp->left);
    }

    return arr;
}

// preorder recursion
void preorderHelper(TreeNode *root, vector<int> &arr)
{
    if (root)
    {
        arr.push_back(root->val);
        preorderHelper(root->left, arr);
        preorderHelper(root->right, arr);
    }
}
vector<int> preorderI(TreeNode *root)
{
    vector<int> arr;
    preorderHelper(root, arr);
    return arr;
}

// inorder iterative
vector<int> inorder(TreeNode *root)
{
    vector<int> arr;
    stack<TreeNode *> st;
    while (true)
    {
        if (!root)
        {
            st.push(root);
            root = root->left;
        }
        else
        {
            if (st.empty())
                break;
            root = st.top();
            arr.push_back(root->val);
            st.pop();
            root = root->right;
        }
    }
    return arr;
}

// inorder recursion
void inorderHelper(TreeNode *root, vector<int> &arr)
{
    if (root)
    {
        inorderHelper(root->left, arr);
        arr.push_back(root->val);
        inorderHelper(root->right, arr);
    }
}

vector<int> inorderI(TreeNode *root)
{
    vector<int> arr;
    inorderHelper(root, arr);
    return arr;
}

// postorder recursion
void postorderHelper(TreeNode *root, vector<int> &arr)
{
    if (root)
    {
        postorderHelper(root->left, arr);
        postorderHelper(root->right, arr);
        arr.push_back(root->val);
    }
}
vector<int> postorderI(TreeNode *root)
{
    vector<int> arr;
    postorderHelper(root, arr);
    return arr;
}

// postorder using double stack
vector<int> postorder(TreeNode *root)
{
    vector<int> arr;
    if (!root)
        return arr;
    stack<TreeNode *> st1;
    stack<TreeNode *> st2;
    st1.push(root);
    while (!st1.empty())
    {
        root = st1.top();
        st1.pop();
        st2.push(root);
        if (root->left)
            st1.push(root->left);
        if (root->right)
            st1.push(root->right);
    }
    while (!st2.empty())
    {
        arr.push_back(st2.top()->val);
        st2.pop();
    }
    return arr;
}

// postorder using single stack
vector<int> postorderII(TreeNode *root)
{
    vector<int> arr;
    if (!root)
    {
        return arr;
    }
    stack<TreeNode *> st;
    while (root || !st.empty())
    {
        if (root)
        {
            st.push(root);
            root = root->left;
        }
        else
        {
            TreeNode *temp = st.top()->right;
            if (!temp)
            {
                temp = st.top();
                st.pop();
                arr.push_back(temp->val);
                while (!st.empty() && temp == st.top()->right)
                {
                    temp = st.top();
                    st.pop();
                    arr.push_back(temp->val);
                }
            }
            else
            {
                root = temp;
            }
        }
    }
    return arr;
}

// level order traversal
vector<vector<int>> levelorder(TreeNode *root)
{
    queue<TreeNode *> q;
    vector<vector<int>> wrapList;
    if (!root)
        return wrapList;
    q.push(root);
    while (!q.empty())
    {
        int lvlNum = q.size();
        vector<int> subList;
        for (int i = 0; i < lvlNum; i++)
        {
            TreeNode *temp = q.front();
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);

            subList.push_back(temp->val);
        }
        wrapList.push_back(subList);
    }
    return wrapList;
}

int main()
{

    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(17);

    cout << countNodes(5) << endl;

    vector<int> ans = preorder(root);
    for (auto &i : ans)
        cout << i << " ";
    cout << endl;

    vector<int> ansI = preorderI(root);
    for (auto &i : ansI)
        cout << i << " ";
    cout << endl;

    return 0;
}