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

ListNode *partition(ListNode *head, int x)
{
    ListNode *lessHead = new ListNode(0);
    ListNode *less = lessHead;
    ListNode *greaterHead = new ListNode(0);
    ListNode *greater = greaterHead;

    while (head)
    {
        if (head->val < x)
        {
            less->next = head;
            less = less->next;
        }
        else
        {
            greater->next = head;
            greater = greater->next;
        }
        head = head->next;
    }

    greater->next = NULL;
    less->next = greaterHead->next;

    return lessHead->next;
}

int main()
{

    ListNode *head = new ListNode(1);
    head->next = new ListNode(4);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(2);

    int k = 3;

    ListNode *ans = partition(head, k);

    while (ans)
    {
        cout << ans->val << "->";
        ans = ans->next;
    }
    cout << "NULL";

    return 0;
}