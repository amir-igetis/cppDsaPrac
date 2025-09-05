#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
    if (!l1)
        return l2;
    if (!l2)
        return l1;

    if (l1->val < l2->val)
    {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    }
    else
    {
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
}

ListNode *mergeLists(vector<ListNode *> &lists, int left, int right)
{
    if (left == right)
        return lists[left];

    int mid = left + (right - left) / 2;
    ListNode *l1 = mergeLists(lists, left, mid);
    ListNode *l2 = mergeLists(lists, mid + 1, right);
    return mergeTwoLists(l1, l2);
}

ListNode *mergeKLists(vector<ListNode *> &lists)
{
    if (lists.empty())
        return nullptr;
    return mergeLists(lists, 0, lists.size() - 1);
}

void printList(ListNode *head)
{
    while (head)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    // First list: 1 -> 4 -> 5
    ListNode *l1 = new ListNode(1);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(5);

    // Second list: 1 -> 3 -> 4
    ListNode *l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);

    // Third list: 2 -> 6
    ListNode *l3 = new ListNode(2);
    l3->next = new ListNode(6);

    vector<ListNode *> lists = {l1, l2, l3};
    ListNode *ans = mergeKLists(lists);

    printList(ans); // Expected output: 1 1 2 3 4 4 5 6

    return 0;
}
