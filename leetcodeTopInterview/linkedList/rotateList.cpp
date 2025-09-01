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

ListNode *rotateRight(ListNode *head, int k)
{
    if (!head || !head->next || k == 0)
        return head;

    ListNode *temp = head;
    int len = 1;
    while (temp->next)
    {
        len++;
        temp = temp->next;
    }

    temp->next = head;

    k = k % len;
    int end = len - k;
    ListNode *newTemp = head;
    for (int i = 1; i < end; i++)
    {
        newTemp = newTemp->next;
    }
    head = newTemp->next;
    newTemp->next = NULL;
    return head;
}

int main()
{

    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int k = 2;

    ListNode *ans = rotateRight(head, k);

    while (ans)
    {
        cout << ans->val << "->";
        ans = ans->next;
    }
    cout << "NULL";

    return 0;
}