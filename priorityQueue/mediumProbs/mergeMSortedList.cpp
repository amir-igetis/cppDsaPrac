#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *mergeKLists(vector<ListNode *> &lists)
{
    auto compare = [](ListNode *a, ListNode *b)
    {
        return a->val > b->val;
    };

    priority_queue<ListNode *, vector<ListNode *>, decltype(compare)>
        minHeap(compare);

    for (auto ls : lists)
    {
        if (ls != nullptr)
            minHeap.push(ls);
    }
    ListNode *dummy = new ListNode(0);
    ListNode *curr = dummy;
    while (!minHeap.empty())
    {
        ListNode *node = minHeap.top();
        minHeap.pop();
        curr->next = node;
        curr = curr->next;
        if (node->next != nullptr)
            minHeap.push(node->next);
    }
    return dummy->next;
}

void printList(ListNode *head)
{
    while (head != nullptr)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    ListNode *l1 = new ListNode(1);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(5);

    ListNode *l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);

    ListNode *l3 = new ListNode(2);
    l3->next = new ListNode(6);

    vector<ListNode *> lists = {l1, l2, l3};
    ListNode *ans = mergeKLists(lists);
    printList(ans);
    return 0;
}