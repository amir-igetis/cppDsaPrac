#include <bits/stdc++.h>
using namespace std;

int minRemoval(vector<int> &nums, int k)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int ans = n;
    int right = 0;
    for (int left = 0; left < n; left++)
    {
        while (right < n &&
               nums[right] <= static_cast<long long>(nums[left] * k))
            right++;

        ans = min(ans, n - (right - left));
    }
    return ans;
}

int main()
{

    vector<int> nums = {2, 1, 5};
    int k = 2;
    cout << minRemoval(nums, k) << endl;

    return 0;
}