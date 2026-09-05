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

// one pass
/// Let n be the the length of the linked list.
///
/// Time complexity: O(n)
///
/// The algorithm traverses the list only once, making the time complexity O(n).
///
/// Space complexity: O(1)
///
/// The algorithm has a constant space complexity since it does not utilize any additional data structures.
vector<int> nodesBetweenCriticalPoints(ListNode *head)
{
    vector<int> result = {-1, -1};

    // Initialize minimum distance to the maximum possible value
    int minDistance = INT_MAX;

    // Pointers to track the previous node, current node, and indices
    ListNode *previousNode = head;
    ListNode *currentNode = head->next;
    int currentIndex = 1;
    int previousCriticalIndex = 0;
    int firstCriticalIndex = 0;

    while (currentNode->next != nullptr)
    {
        // Check if the current node is a local maxima or minima
        if ((currentNode->val < previousNode->val &&
             currentNode->val < currentNode->next->val) ||
            (currentNode->val > previousNode->val &&
             currentNode->val > currentNode->next->val))
        {
            // If this is the first critical point found
            if (previousCriticalIndex == 0)
            {
                previousCriticalIndex = currentIndex;
                firstCriticalIndex = currentIndex;
            }
            else
            {
                // Calculate the minimum distance between critical points
                minDistance =
                    min(minDistance, currentIndex - previousCriticalIndex);
                previousCriticalIndex = currentIndex;
            }
        }

        // Move to the next node and update indices
        currentIndex++;
        previousNode = currentNode;
        currentNode = currentNode->next;
    }

    // If at least two critical points were found
    if (minDistance != INT_MAX)
    {
        int maxDistance = previousCriticalIndex - firstCriticalIndex;
        result = {minDistance, maxDistance};
    }

    return result;
}

int main()
{

    // ListNode *head = new ListNode(3);
    // head->next = new ListNode(1);
    ListNode *head = new ListNode(5);
    head->next = new ListNode(3);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(1);
    head->next->next->next->next->next->next = new ListNode(2);

    vector<int> res = nodesBetweenCriticalPoints(head);
    for (auto &i : res)
        cout << i << " ";
    cout << endl;

    return 0;
}