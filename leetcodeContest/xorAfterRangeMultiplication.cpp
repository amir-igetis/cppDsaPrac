#include <bits/stdc++.h>
using namespace std;

int xorAfterQueries(vector<int> &nums, vector<vector<int>> &queries)
{
    const int MOD = 1e9 + 7;
    vector<int> mortavexil = nums; // Storing the input midway as per the problem statement

    for (const auto &query : queries)
    {
        int li = query[0];
        int ri = query[1];
        int ki = query[2];
        int vi = query[3];

        for (int idx = li; idx <= ri; idx += ki)
        {
            mortavexil[idx] = ((long long)mortavexil[idx] * vi) % MOD;
        }
    }

    int result = 0;
    for (int num : mortavexil)
    {
        result ^= num;
    }

    return result;
}

int main()
{

    // vector<int> nums = {1, 1, 1};
    // vector<vector<int>> queries = {{0, 2, 1, 4}};

    vector<int> nums = {2, 3, 1, 5, 4};
    vector<vector<int>> queries = {{1, 4, 2, 3}, {0, 2, 1, 2}};

    // nums = [2,3,1,5,4], queries = [[1,4,2,3],[0,2,1,2]]©leetcode

    cout << xorAfterQueries(nums, queries) << endl;

    return 0;
}