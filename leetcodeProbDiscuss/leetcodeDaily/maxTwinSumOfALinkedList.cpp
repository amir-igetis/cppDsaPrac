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

int pairSum(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;
    int maxVal = 0;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode *nextNode, *prev = nullptr;
    while (slow)
    {
        nextNode = slow->next;
        slow->next = prev;
        prev = slow;
        slow = nextNode;
    }
    while (prev)
    {
        maxVal = max(maxVal, head->val + prev->val);
        prev = prev->next;
        head = head->next;
    }
    return maxVal;
}

int main()
{
    ListNode *head = new ListNode(5);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);

    cout << pairSum(head) << endl;

    return 0;
}