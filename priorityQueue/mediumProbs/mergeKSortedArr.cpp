#include <bits/stdc++.h>
using namespace std;

vector<int> mergeKArrays(vector<vector<int>> arr, int k)
{
    vector<int> res;
    priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> minHeap;
    for (int i = 0; i < k; i++)
    {
        if (!arr[i].empty())
            minHeap.push({arr[i][0], i, 0});
    }

    while (!minHeap.empty())
    {
        auto curr = minHeap.top();
        minHeap.pop();
        int val = curr[0];
        int row = curr[1];
        int col = curr[2];
        res.push_back(val);

        if (col + 1 < arr[row].size())
        {
            minHeap.push({arr[row][col + 1], row, col + 1});
        }
    }
    return res;
}

int main()
{

    vector<vector<int>> arr = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    int k = 3;
    vector<int> mergedArray = mergeKArrays(arr, k);

    for (int num : mergedArray)
    {
        cout << num << " ";
    }
}