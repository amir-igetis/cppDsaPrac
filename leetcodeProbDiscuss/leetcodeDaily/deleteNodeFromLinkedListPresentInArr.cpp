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

ListNode *modifiedList(vector<int> &nums, ListNode *head)
{
    unordered_set<int> numSet;
    for (auto &num : nums)
    {
        numSet.insert(num);
    }

    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *curr = dummy;

    while (curr->next != NULL)
    {
        if (numSet.count(curr->next->val))
            curr->next = curr->next->next;
        else
            curr = curr->next;
    }

    return dummy->next;
}

int main()
{

    vector<int> nums = {1, 2, 3};
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    ListNode *ans = modifiedList(nums, head);

    while (ans != NULL)
    {
        cout << ans->val << " ";
        ans = ans->next;
    }
    cout << endl;

    return 0;
}