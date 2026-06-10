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

// Convert to Graph with Breadth First Search tc & sc O(n)
TreeNode *createBinaryTree(vector<vector<int>> &descriptions)
{
    // Sets to track unique children and parents
    unordered_set<int> children, parents;
    // Map to store parent to children relationships
    unordered_map<int, vector<pair<int, int>>> parentToChildren;

    // Build graph from parent to child, and add nodes to HashSets
    for (auto &d : descriptions)
    {
        int parent = d[0], child = d[1], isLeft = d[2];
        parents.insert(parent);
        parents.insert(child);
        children.insert(child);
        parentToChildren[parent].emplace_back(child, isLeft);
    }

    // Find the root node by checking which node is in parents but not in
    // children
    for (auto it = parents.begin(); it != parents.end();)
    {
        if (children.find(*it) != children.end())
        {
            it = parents.erase(it);
        }
        else
        {
            ++it;
        }
    }
    TreeNode *root = new TreeNode(*parents.begin());

    // Starting from root, use BFS to construct binary tree
    queue<TreeNode *> queue;
    queue.push(root);

    while (!queue.empty())
    {
        TreeNode *parent = queue.front();
        queue.pop();
        // Iterate over children of current parent
        for (auto &childInfo : parentToChildren[parent->val])
        {
            int childValue = childInfo.first, isLeft = childInfo.second;
            TreeNode *child = new TreeNode(childValue);
            queue.push(child);
            // Attach child node to its parent based on isLeft flag
            if (isLeft == 1)
            {
                parent->left = child;
            }
            else
            {
                parent->right = child;
            }
        }
    }

    return root;
}

// Convert to Graph with Depth First Search tc & sc O(n)
TreeNode *dfs(unordered_map<int, vector<pair<int, bool>>> &parentToChildren,
              int val)
{
    // Create new TreeNode for current value
    TreeNode *node = new TreeNode(val);

    // If current node has children, recursively build them
    if (parentToChildren.find(val) != parentToChildren.end())
    {
        for (auto &child_info : parentToChildren[val])
        {
            int child = child_info.first;
            bool isLeft = child_info.second;

            // Attach child node based on isLeft flag
            if (isLeft)
            {
                node->left = dfs(parentToChildren, child);
            }
            else
            {
                node->right = dfs(parentToChildren, child);
            }
        }
    }

    return node;
}

TreeNode *createBinaryTreeI(vector<vector<int>> &descriptions)
{
    // Step 1: Organize data
    unordered_map<int, vector<pair<int, bool>>> parentToChildren;
    unordered_set<int> allNodes;
    unordered_set<int> children;

    for (auto &desc : descriptions)
    {
        int parent = desc[0];
        int child = desc[1];
        bool isLeft = desc[2];

        parentToChildren[parent].push_back({child, isLeft});
        allNodes.insert(parent);
        allNodes.insert(child);
        children.insert(child);
    }

    // Step 2: Find the root
    int rootVal = 0;
    for (int node : allNodes)
    {
        if (!children.count(node))
        {
            rootVal = node;
            break;
        }
    }

    // Step 3 & 4: Build the tree using DFS
    return dfs(parentToChildren, rootVal);
}

// Constructing Tree From Directly Map and TreeNode Object tc & sc O(n)
TreeNode *createBinaryTreeII(vector<vector<int>> &descriptions)
{
    // Maps values to TreeNode pointers
    unordered_map<int, TreeNode *> nodeMap;
    // Stores values which are children in the descriptions
    unordered_set<int> children;

    // Iterate through descriptions to create nodes and set up tree
    // structure
    for (const auto &description : descriptions)
    {
        // Extract parent value, child value, and whether it is a
        // left child (1) or right child (0)
        int parentValue = description[0];
        int childValue = description[1];
        bool isLeft = description[2];

        // Create parent and child nodes if not already created
        if (nodeMap.count(parentValue) == 0)
        {
            nodeMap[parentValue] = new TreeNode(parentValue);
        }
        if (nodeMap.count(childValue) == 0)
        {
            nodeMap[childValue] = new TreeNode(childValue);
        }

        // Attach child node to parent's left or right branch
        if (isLeft)
        {
            nodeMap[parentValue]->left = nodeMap[childValue];
        }
        else
        {
            nodeMap[parentValue]->right = nodeMap[childValue];
        }

        // Mark child as a child in the set
        children.insert(childValue);
    }

    // Find and return the root node
    for (auto &entry : nodeMap)
    {
        auto &value = entry.first;
        auto &node = entry.second;
        // Root node found
        if (children.find(value) == children.end())
        {
            return node;
        }
    }

    // Should not occur according to problem statement
    return nullptr;
}

void printList(TreeNode *root)
{
    if (root)
    {
        printList(root->left);
        cout << root->val << " ";
        printList(root->right);
    }
}

int main()
{
    vector<vector<int>> description = {{20, 15, 1}, {20, 17, 0}, {50, 20, 1}, {50, 80, 0}, {80, 19, 1}};
    TreeNode *root = createBinaryTreeI(description);
    printList(root);

    return 0;
}