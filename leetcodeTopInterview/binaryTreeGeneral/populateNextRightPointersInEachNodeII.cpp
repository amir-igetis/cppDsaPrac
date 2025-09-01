#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

Node *connect(Node *root)
{
    if (!root)
        return nullptr;

    Node *head = root;
    while (head)
    {
        Node *dummy = new Node(0);
        Node *curr = dummy;
        for (Node *node = head; node; node = node->next)
        {
            if (node->left)
            {
                curr->next = node->left;
                curr = curr->next;
            }
            if (node->right)
            {
                curr->next = node->right;
                curr = curr->next;
            }
        }
        head = dummy->next;
    }
    return root;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(7);

    // Call function
    root = connect(root);

    // Print levels using next pointers
    Node *level = root;
    while (level)
    {
        Node *curr = level;
        while (curr)
        {
            cout << curr->val << " -> ";
            curr = curr->next;
        }
        cout << "NULL" << endl;

        // Move to next level
        if (level->left)
            level = level->left;
        else if (level->right)
            level = level->right;
        else
        {
            Node *temp = level->next;
            while (temp && !temp->left && !temp->right)
                temp = temp->next;
            level = temp ? (temp->left ? temp->left : temp->right) : nullptr;
        }
    }

    return 0;
}