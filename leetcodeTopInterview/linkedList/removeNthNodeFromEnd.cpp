
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

// deleting the nth from last node is same as deleting (len - n + 1)

ListNode *removeNthFromEnd(ListNode *head, int n)
{

    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *first = dummy;
    ListNode *second = dummy;

    for (int i = 0; i <= n; i++)
    {
        first = first->next;
    }

    while (first)
    {
        first = first->next;
        second = second->next;
    }

    second->next = second->next->next;
    return dummy->next;
}

int main()
{

    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int n = 2;

    ListNode *ans = removeNthFromEnd(head, n);

    while (ans)
    {
        cout << ans->val << "->";
        ans = ans->next;
    }
    cout << "NULL";

    return 0;
}