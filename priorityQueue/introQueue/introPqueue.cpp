#include <bits/stdc++.h>
using namespace std;

int extractMax(vector<int> arr, int k)
{
    priority_queue<int> q;
    // default max heap
    for (int i = 0; i < arr.size(); i++)
    {
        q.push(arr[i]);
        if (q.size() > k)
            q.pop();
    }
    return q.top();
}

int kthLargest(vector<int> &arr, int k)
{
    priority_queue<int, vector<int>, greater<int>> q;
    // min heap
    for (int i = 0; i < arr.size(); i++)
    {
        q.push(arr[i]);
        if (q.size() > k)
            q.pop();
    }
    return q.top();
}

int main()
{
    vector<int> array = {3, 2, 1, 5, 6, 4};
    int k = 2;

    cout << "The " << k << "th largest element is: " << kthLargest(array, k) << endl;
    cout << "Extracted max element: " << extractMax(array, k) << endl;

    return 0;
}