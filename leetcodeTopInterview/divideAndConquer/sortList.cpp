#include <bits/stdc++.h>
using namespace std;

struct
    ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *getMiddle(ListNode *head)
{
    ListNode *slow = head, *fast = head;
    while (fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

ListNode *merge(ListNode *l1, ListNode *l2)
{
    ListNode *dummy = new ListNode(0);
    ListNode *curr = dummy;

    while (l1 && l2)
    {
        if (l1->val < l2->val)
        {
            curr->next = l1;
            l1 = l1->next;
        }
        else
        {
            curr->next = l2;
            l2 = l2->next;
        }

        curr = curr->next;
    }
    if (l1)
        curr->next = l1;
    if (l2)
        curr->next = l2;

    return dummy->next;
}

ListNode *sortList(ListNode *head)
{
    if (!head || !head->next)
        return head;

    ListNode *mid = getMiddle(head);
    ListNode *rightHalf = mid->next;
    mid->next = NULL;

    ListNode *left = sortList(head);
    ListNode *right = sortList(rightHalf);

    return merge(left, right);
}

void printList(ListNode *head)
{
    while (head)
    {
        cout << head->val << "->";
        head = head->next;
    }
    cout << "NULL";
    cout << endl;
}

int main()
{

    ListNode *head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);

    ListNode *ans = sortList(head);
    printList(ans);

    return 0;
}