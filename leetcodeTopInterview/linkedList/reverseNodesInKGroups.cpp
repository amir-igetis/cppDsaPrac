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

ListNode *reverseKGroup(ListNode *head, int k)
{
    ListNode *curr = head;
    int count = 0;

    while (curr && count < k)
    {
        curr = curr->next;
        count++;
    }

    if (count == k)
    {
        ListNode *prev = NULL;
        ListNode *next = NULL;
        curr = head;

        for (int i = 0; i < k; i++)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head->next = reverseKGroup(curr, k);
        return prev;
    }
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

    ListNode *ans = reverseKGroup(head, k);

    while (ans)
    {
        cout << ans->val << "->";
        ans = ans->next;
    }
    cout << "NULL";

    return 0;
}