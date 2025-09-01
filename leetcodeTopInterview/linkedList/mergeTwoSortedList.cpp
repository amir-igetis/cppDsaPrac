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

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    ListNode *dummy = new ListNode(0);
    ListNode *current = dummy;

    while (list1 || list2)
    {
        int v1 = (!list1 ? INT_MAX : list1->val);
        int v2 = (!list2 ? INT_MAX : list2->val);

        if (v1 < v2)
        {
            current->next = list1;
            list1 = list1->next;
        }
        else
        {
            current->next = list2;
            list2 = list2->next;
        }

        current = current->next;
        current->next = NULL;
    }
    return dummy->next;
}

int main()
{
    ListNode *head1 = new ListNode(1);

    ListNode *head2 = new ListNode(1);

    ListNode *ans = mergeTwoLists(head1, head2);

    cout << ans->val << endl;

    return 0;
}