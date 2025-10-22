#include <bits/stdc++.h>
using namespace std;

int maxDistinctElements(vector<int> &nums, int k)
{
    sort(nums.begin(), nums.end());
    int nextAvailable = INT_MIN, distinct = 0;
    for (auto &num : nums)
    {
        int start = num - k, end = num + k;

        if (nextAvailable < start)
            nextAvailable = start;

        if (nextAvailable <= end)
        {
            distinct++;
            nextAvailable++;
        }
    }
    return distinct;
}

int main()
{
    vector<int> nums = {1, 2, 2, 3, 3, 4};
    int k = 2;
    cout << maxDistinctElements(nums, k) << endl;

    return 0;
}