#include <bits/stdc++.h>
using namespace std;

vector<int> replaceWithRand(vector<int> &arr, int N)
{
    vector<int> ranks(N);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
    for (int i = 0; i < N; i++)
        minHeap.push({arr[i], i});

    int rank = 1;
    while (!minHeap.empty())
    {
        pair<int, int> topElement = minHeap.top();
        minHeap.pop();
        ranks[topElement.second] = rank;

        if (!minHeap.empty() && minHeap.top().first != topElement.first)
            rank++;
    }
    return ranks;
}

vector<int> replaceWithRankI(vector<int> &arr)
{
    int n = arr.size();
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Step 1: Insert all elements with their indices into the priority queue
    for (int i = 0; i < n; i++)
    {
        pq.push({arr[i], i});
    }

    int rank = 0;
    int prev = -1;

    // Step 2: Assign ranks while popping elements from the priority queue
    while (!pq.empty())
    {
        auto top = pq.top();
        pq.pop();

        int elem = top.first;
        int indx = top.second;

        // If current element is same as previous, assign the same rank
        if (elem == prev)
        {
            arr[indx] = rank;
        }
        else
        {
            arr[indx] = ++rank;
        }

        prev = elem;
    }

    return arr;
}

void replaceWithRankII(vector<int> &arr)
{
    unordered_map<int, int> mp; // Hash map to store element ranks
    int temp = 1;
    int n = arr.size();
    vector<int> brr(arr); // Create a copy of the original array

    // Step 1: Sort the copied array
    sort(brr.begin(), brr.end());

    // Step 2: Assign ranks to unique elements
    for (int i = 0; i < n; i++)
    {
        // If the element is not already in the map, assign a rank
        if (mp.find(brr[i]) == mp.end())
        {
            mp[brr[i]] = temp++;
        }
    }

    // Step 3: Print the ranks based on the original array
    for (int i = 0; i < n; i++)
    {
        cout << mp[arr[i]] << " ";
    }
    cout << endl;
}

int main()
{
    int N = 6;
    vector<int> arr = {20, 15, 26, 2, 98, 6};
    vector<int> ranks = replaceWithRand(arr, N);
    for (auto &i : ranks)
        cout << i << " ";
    cout << endl;

    return 0;
}