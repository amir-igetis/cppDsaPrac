#include <bits/stdc++.h>
using namespace std;

// ------------------------------------------------------------
// 1. Sorting + Hash Map
// Time : O(n log n)
// Space: O(n)
// ------------------------------------------------------------
vector<int> arrayRankTransform(vector<int> arr)
{

    unordered_map<int, int> numToRank;

    vector<int> sortedArr = arr;
    sort(sortedArr.begin(), sortedArr.end());

    int rank = 1;

    for (int i = 0; i < (int)sortedArr.size(); i++)
    {
        if (i > 0 && sortedArr[i] > sortedArr[i - 1])
            rank++;

        numToRank[sortedArr[i]] = rank;
    }

    for (int &x : arr)
        x = numToRank[x];

    return arr;
}

// ------------------------------------------------------------
// 2. Deduplicate using Set
// Time : O(n log n)
// Space: O(n)
// ------------------------------------------------------------
vector<int> arrayRankTransformI(vector<int> arr)
{

    unordered_map<int, int> numToRank;
    set<int> nums(arr.begin(), arr.end());

    int rank = 1;

    for (int num : nums)
        numToRank[num] = rank++;

    for (int &x : arr)
        x = numToRank[x];

    return arr;
}

// ------------------------------------------------------------
// 3. Ordered Map
// Time : O(n log n)
// Space: O(n)
// ------------------------------------------------------------
vector<int> arrayRankTransformII(vector<int> arr)
{

    map<int, vector<int>> numToIndices;

    for (int i = 0; i < (int)arr.size(); i++)
        numToIndices[arr[i]].push_back(i);

    int rank = 1;

    for (auto &entry : numToIndices)
    {
        for (int idx : entry.second)
            arr[idx] = rank;

        rank++;
    }

    return arr;
}

int main()
{

    vector<int> nums = {40, 10, 20, 30};

    auto print = [](const vector<int> &v)
    {
        for (int x : v)
            cout << x << " ";
        cout << endl;
    };

    print(arrayRankTransform(nums));
    print(arrayRankTransformI(nums));
    print(arrayRankTransformII(nums));

    return 0;
}
