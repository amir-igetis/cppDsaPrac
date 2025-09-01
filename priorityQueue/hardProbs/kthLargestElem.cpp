#include <bits/stdc++.h>
using namespace std;

class KthLargest
{
public:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int k;

    KthLargest(int k, vector<int> &nums)
    {
        this->k = k;
        for (int num : nums)
        {
            minHeap.push(num);
            if (minHeap.size() > k)
                minHeap.pop();
        }
    }

    int add(int val)
    {
        minHeap.push(val);
        if (minHeap.size() > k)
            minHeap.pop();
        return minHeap.top();
    }
};

long long minCost(vector<long long> arr, int n)
{
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int i = 0; i < n; i++)
    {
        minHeap.push(arr[i]);
    }
    long long res = 0;
    while (minHeap.size() > 1)
    {
        long long first = minHeap.top();
        minHeap.pop();
        long second = minHeap.top();
        minHeap.pop();
        long long sum = first + second;
        res += sum;
        minHeap.push(sum);
    }
    return res;
}

int main()
{
    vector<int> nums = {4, 5, 8, 2};
    int k = 3;
    KthLargest kthLargest(k, nums);

    cout << kthLargest.add(3) << endl;  // returns 4
    cout << kthLargest.add(5) << endl;  // returns 5
    cout << kthLargest.add(10) << endl; // returns 5
    cout << kthLargest.add(9) << endl;  // returns 8
    cout << kthLargest.add(4) << endl;  // returns 8

    return 0;
}