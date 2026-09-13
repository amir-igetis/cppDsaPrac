#include <bits/stdc++.h>
using namespace std;

// dp + binary search

/// Let n be the length of the array intervals, and let k=4.
///
/// Time complexity: O(nlogn+nk^2).
///
/// Sorting the intervals takes O(nlogn) time. For each interval, finding the non-overlapping prefix via binary search takes O(logn) time, totaling O(nlogn) across all intervals. There are O(nk) dynamic programming states, and maintaining each index list takes O(k) time. Therefore, the total time complexity is O(nlogn+n^2)
///
/// Space complexity: O(nk^2)
///
/// An array of length O(n) is required to store the sorted intervals. There are O(nk) dynamic programming states, and storing the index list for each state requires O(k) space. Therefore, the total space complexity is O(nk^2)

vector<int> maximumWeight(vector<vector<int>> &intervals)
{
    int n = intervals.size();
    vector<tuple<int, int, int, int>> arr;
    for (int i = 0; i < n; i++)
    {
        int l = intervals[i][0], r = intervals[i][1],
            weight = intervals[i][2];
        arr.emplace_back(l, r, weight, i);
    }
    // Sort by right endpoint.
    sort(arr.begin(), arr.end(),
         [](auto &&a, auto &&b)
         { return get<1>(a) < get<1>(b); });

    vector<vector<long long>> dp(n + 1, vector<long long>(5));
    vector<vector<vector<int>>> indices(n + 1, vector<vector<int>>(5));
    for (int i = 0; i < n; i++)
    {
        int l = get<0>(arr[i]);
        int r = get<1>(arr[i]);
        int weight = get<2>(arr[i]);
        int idx = get<3>(arr[i]);

        // Find the first interval whose right endpoint
        // is >= l.
        //
        // Therefore, all intervals before k have:
        // right endpoint < l
        int k = lower_bound(arr.begin(), arr.begin() + i, l,
                            [](const tuple<int, int, int, int> &t,
                               int val)
                            { return get<1>(t) < val; }) -
                arr.begin();

        for (int j = 1; j < 5; j++)
        {
            long long s1 = dp[i][j];
            long long s2 = dp[k][j - 1] + weight;
            if (s1 > s2)
            {
                dp[i + 1][j] = dp[i][j];
                indices[i + 1][j] = indices[i][j];
                continue;
            }

            vector<int> newIndex = indices[k][j - 1];
            newIndex.push_back(idx);
            sort(newIndex.begin(), newIndex.end());
            if (s1 == s2 && indices[i][j] < newIndex)
            {
                newIndex = indices[i][j];
            }
            dp[i + 1][j] = s2;
            indices[i + 1][j] = newIndex;
        }
    }

    return indices[n][4];
}

int main()
{

    vector<vector<int>> intervals = {{1, 2, 4}, {3, 5, 3}, {0, 6, 5}, {8, 9, 2}, {5, 7, 2}};
    vector<int> result = maximumWeight(intervals);
    for (int i : result)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}