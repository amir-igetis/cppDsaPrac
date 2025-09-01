#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

Node *cloneGraph(Node *node)
{
    if (!node)
        return NULL;

    unordered_map<Node *, Node *> mp;
    queue<Node *> q;

    Node *clone = new Node(node->val);
    mp[node] = clone;
    q.push(node);

    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();
        for (Node *neigh : curr->neighbors)
        {
            if (mp.find(neigh) == mp.end())
            {
                mp[neigh] = new Node(neigh->val);
                q.push(neigh);
            }
            mp[curr]->neighbors.push_back(mp[neigh]);
        }
    }

    return clone;
}

void printGraph(Node *node)
{
    if (!node)
        return;
    unordered_set<Node *> visited;
    queue<Node *> q;
    q.push(node);
    visited.insert(node);

    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();

        cout << "Node " << curr->val << " -> ";
        for (auto neigh : curr->neighbors)
        {
            cout << neigh->val << " ";
            if (!visited.count(neigh))
            {
                visited.insert(neigh);
                q.push(neigh);
            }
        }
        cout << endl;
    }
}

int main()
{
    // Build a sample graph:
    // 1 -- 2
    // |    |
    // 4 -- 3

    Node *node1 = new Node(1);
    Node *node2 = new Node(2);
    Node *node3 = new Node(3);
    Node *node4 = new Node(4);

    node1->neighbors = {node2, node4};
    node2->neighbors = {node1, node3};
    node3->neighbors = {node2, node4};
    node4->neighbors = {node1, node3};

    cout << "Original Graph:" << endl;
    printGraph(node1);

    Node *cloned = cloneGraph(node1);

    cout << "\nCloned Graph:" << endl;
    printGraph(cloned);

    return 0;
}