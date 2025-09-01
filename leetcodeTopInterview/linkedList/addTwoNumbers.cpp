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

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *dummy = new ListNode(0);
    ListNode *curr = dummy;
    int carry = 0;

    while (l1 || l2)
    {
        int sum = carry;

        if (l1)
        {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2)
        {
            sum += l2->val;
            l2 = l2->next;
        }

        carry = sum / 10;
        curr->next = new ListNode(sum % 10);
        curr = curr->next;
    }

    if (carry > 0)
    {
        curr->next = new ListNode(carry);
    }

    return dummy->next;
}

int main()
{

    ListNode *l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
    ListNode *l2 = new ListNode(5, new ListNode(6, new ListNode(4)));

    ListNode *ans = addTwoNumbers(l1, l2);

    while (ans)
    {
        cout << ans->val << " ";
        ans = ans->next;
    }
    cout << endl;

    return 0;
}