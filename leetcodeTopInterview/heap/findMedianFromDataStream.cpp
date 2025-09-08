#include <bits/stdc++.h>
using namespace std;

class MedianFinder
{
public:
    // Max heap (left half)
    priority_queue<int> maxHeap;
    // Min heap (right half)
    priority_queue<int, vector<int>, greater<int>> minHeap;

    MedianFinder() {}

    void addNum(int num)
    {
        maxHeap.push(num);

        // Balance: move the largest from maxHeap to minHeap
        minHeap.push(maxHeap.top());
        maxHeap.pop();

        // Ensure maxHeap has >= minHeap elements
        if (maxHeap.size() < minHeap.size())
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double findMedian()
    {
        if (maxHeap.size() == minHeap.size())
        {
            return (maxHeap.top() + minHeap.top()) / 2.0;
        }
        else
        {
            return maxHeap.top(); // maxHeap always has 1 extra element
        }
    }
};

int main()
{

    MedianFinder mf;
    mf.addNum(1);
    mf.addNum(2);
    cout << mf.findMedian() << endl; // 1.5
    mf.addNum(3);
    cout << mf.findMedian() << endl; // 2
    return 0;

    return 0;
}