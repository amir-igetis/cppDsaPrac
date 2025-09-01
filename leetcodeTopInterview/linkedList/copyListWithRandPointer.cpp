#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node *copyRandomList(Node *head)
{
    if (!head)
        return NULL;
    unordered_map<Node *, Node *> mp;
    Node *curr = head;

    while (curr)
    {
        // mp.insert(curr, new Node* (curr));
        mp[curr] = new Node(curr->val);
        curr = curr->next;
    }

    curr = head;
    while (curr)
    {
        mp[curr]->next = mp[curr->next];
        mp[curr]->random = mp[curr->random];
        curr = curr->next;
    }
    return mp[head];
}

Node *copyRandomListI(Node *head)
{
    if (head == nullptr)
        return nullptr;

    Node *curr = head;
    // Step 1: Insert copies after each node
    while (curr != nullptr)
    {
        Node *copy = new Node(curr->val);
        copy->next = curr->next;
        curr->next = copy;
        curr = copy->next;
    }

    // Step 2: Assign random pointers
    curr = head;
    while (curr != nullptr)
    {
        if (curr->random != nullptr)
        {
            curr->next->random = curr->random->next;
        }
        curr = curr->next->next;
    }

    // Step 3: Separate the two lists
    curr = head;
    Node *dummy = new Node(0);
    Node *copyCurr = dummy;
    while (curr != nullptr)
    {
        copyCurr->next = curr->next;
        curr->next = curr->next->next;
        curr = curr->next;
        copyCurr = copyCurr->next;
    }

    return dummy->next;
}

int main()
{

    Node *head = new Node(7);
    Node *ans = copyRandomList(head);

    cout << ans->val << endl;

    return 0;
}