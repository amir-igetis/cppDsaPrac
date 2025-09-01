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

ListNode *reverseBetween(ListNode *head, int left, int right)
{
    if (!head)
        return NULL;

    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *pre = dummy;

    for (int i = 0; i < left - 1; i++)
        pre = pre->next;

    ListNode *curr = pre->next;
    ListNode *prev = NULL;

    for (int i = 0; i < right - left + 1; i++)
    {
        ListNode *nextTemp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextTemp;
    }

    pre->next->next = curr;
    pre->next = prev;

    return dummy->next;
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
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int left = 2, right = 4;
    ListNode *ans = reverseBetween(head, left, right);
    printList(ans);

    return 0;
}