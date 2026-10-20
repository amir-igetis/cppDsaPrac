#include <bits/stdc++.h>
using namespace std;

// greedy

/// Let n be the length of nums_1 and nums_2
///
/// Time complexity: O(nlogn).
///
/// Computing the absolute differences takes O(n) time. Sorting the array of size n takes O(nlogn) time. The subsequent linear pass to reduce the elements takes O(n) time. Thus, the overall time complexity is dominated by sorting: O(nlogn).
///
/// Space complexity: O(n) or O(logn).
///
/// Extra space is required to store and sort the differences. In languages like Python and Java, an auxiliary array of size O(n) is allocated. For in-place implementations, the built-in sorting algorithm uses O(logn) to O(n) auxiliary space depending on the language.
long long minSumSquareDiff(vector<int> &nums1, vector<int> &nums2, int k1,
                           int k2)
{
    long long k = (long long)k1 + k2;
    int n = nums1.size();
    for (int i = 0; i < n; i++)
    {
        nums1[i] = abs(nums1[i] - nums2[i]);
    }
    if (accumulate(nums1.begin(), nums1.end(), 0LL) <= k)
    {
        return 0;
    }
    sort(nums1.begin(), nums1.end(), greater<int>());
    nums1.push_back(0);
    for (int i = 1; i <= n; i++)
    {
        long long cost = (long long)(nums1[i - 1] - nums1[i]) * i;
        if (cost > k)
        {
            long long q = k / i, r = k % i;
            long long hi = nums1[i - 1] - q;
            long long ans = hi * hi * (i - r) + (hi - 1) * (hi - 1) * r;
            for (int j = i; j < n; j++)
            {
                ans += (long long)nums1[j] * nums1[j];
            }
            return ans;
        }
        k -= cost;
    }
    return 0;
}

// binary search on answer

/// Let n be the length of nums_1 and nums_2 and let m be the maximum absolute difference between corresponding elements of the two arrays.
///
/// Time complexity: O(n(logn+logm)).
///
/// Finding the maximum difference takes O(n) time. Binary search takes O(nlogm) time across O(logm) iterations. Sorting the array takes O(nlogn) time, and the final pass takes O(n) time. Thus, the overall time complexity is O(n(logn+logm)).
///
/// Space complexity: O(n) or O(logn).
///
/// Extra space is required for sorting, taking O(logn) to O(n) auxiliary space depending on the programming language.
long long minSumSquareDiffI(vector<int> &nums1, vector<int> &nums2, int k1,
                            int k2)
{
    int n = nums1.size();
    long long ans = 0;
    int k = k1 + k2;
    int maxDif = 0;
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        nums1[i] = abs(nums1[i] - nums2[i]);
        maxDif = max(maxDif, nums1[i]);
    }
    int l = 0, r = maxDif;
    auto check = [&](int mid) -> bool
    {
        long long sum = 0;
        for (int num : nums1)
        {
            sum += num > mid ? num - mid : 0;
        }
        return sum <= k;
    };
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (check(mid))
        {
            r = mid - 1;
            res = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (nums1[i] > res)
        {
            k -= (nums1[i] - res);
        }
    }
    sort(nums1.begin(), nums1.end(), greater<int>());
    for (int num : nums1)
    {
        long long diff = res >= num ? num : res;
        if (k && diff)
        {
            diff--;
            k--;
        }
        ans += diff * diff;
    }
    return ans;
}

int main()
{
    vector<int> nums1 = {1, 4, 10, 12}, nums2 = {5, 8, 6, 9};
    int k1 = 1, k2 = 1;
    cout << minSumSquareDiff(nums1, nums2, k1, k2) << endl;
    cout << minSumSquareDiffI(nums1, nums2, k1, k2) << endl;

    return 0;
}