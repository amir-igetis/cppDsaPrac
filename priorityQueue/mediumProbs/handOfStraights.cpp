#include <bits/stdc++.h>
using namespace std;

bool isNStraightHand(vector<int> &hand, int groupSize)
{
    if (hand.size() % groupSize != 0)
        return false;
    unordered_map<int, int> mp;
    for (int card : hand)
        mp[card]++;

    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (auto &entry : mp)
        minHeap.push(entry.first);

    while (!minHeap.empty())
    {
        int start = minHeap.top();
        minHeap.pop();
        for (int i = 0; i < groupSize; i++)
        {
            int card = start + i;
            if (mp[card] == 0)
                return false;

            mp[card]--;

            if (mp[card] == 0 && !minHeap.empty() && card == minHeap.top())
                minHeap.pop();
        }
    }
    return true;
}

int main()
{

    vector<int> hand = {1, 2, 3, 6, 2, 3, 4, 7, 8};
    int groupSize = 3;
    cout << boolalpha << isNStraightHand(hand, groupSize) << endl; // Output: true

    return 0;
}