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

ListNode *deleteDuplicates(ListNode *head)
{
    if (!head)
        return NULL;

    ListNode *dummy = new ListNode(0);
    dummy->next = head;

    ListNode *prev = dummy;

    while (head)
    {
        if (head->next && head->val == head->next->val)
        {
            while (head->next && head->val == head->next->val)
                head = head->next;

            prev->next = head->next;
        }
        else
        {
            prev = prev->next;
        }
        head = head->next;
    }

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

    ListNode *ans = deleteDuplicates(head);

    while (ans)
    {
        cout << ans->val << "->";
        ans = ans->next;
    }
    cout << "NULL";

    return 0;
}