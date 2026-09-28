#include <bits/stdc++.h>
using namespace std;

int minOperations(vector<int> &nums, int x)
{
    // Replaced reduce with accumulate and provided 0 as the initial sum value
    int k = accumulate(nums.begin(), nums.end(), 0) - x, n = nums.size();
    if (k < 0)
        return -1;
    if (k == 0)
        return n;

    int best = -1, i = 0, sum = 0;
    for (int j = 0; j < n; j++)
    {
        sum += nums[j];
        while (sum > k)
            sum -= nums[i++];

        if (sum == k)
            best = max(best, j - i + 1);
    }

    return best + 1 ? n - best : -1;
}

int main()
{
    vector<int> nums = {1, 1, 4, 2, 3};
    int x = 5;
    cout << minOperations(nums, x) << endl;

    return 0;
}