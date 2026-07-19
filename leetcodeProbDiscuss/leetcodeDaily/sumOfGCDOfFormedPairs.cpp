#include <bits/stdc++.h>
using namespace std;

long long gcdSum(vector<int> &nums)
{
    int n = nums.size();
    vector<int> mx(n);
    int prefixMax = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        prefixMax = max(prefixMax, nums[i]);
        mx[i] = prefixMax;
    }
    vector<int> prefixGcd(n);
    for (int i = 0; i < n; i++)
        prefixGcd[i] = __gcd(nums[i], mx[i]);

    sort(prefixGcd.begin(), prefixGcd.end());

    long ans = 0;
    int left = 0, right = n - 1;
    while (left < right)
    {
        ans += __gcd(prefixGcd[left], prefixGcd[right]);
        left++;
        right--;
    }
    return ans;
}

int main()
{

    vector<int> nums = {2, 6, 4};
    cout << gcdSum(nums) << endl;

    return 0;
}
