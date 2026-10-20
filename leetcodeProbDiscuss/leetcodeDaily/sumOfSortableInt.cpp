#include <bits/stdc++.h>
using namespace std;

// KMP

/// Let n be the length of nums, and let k denote a divisor of n being checked.
///
/// Time complexity: O(n(sqrt(n))).
///
/// There are O(sqrt(n)) divisors of n. For each divisor k, nums is partitioned into
/// n / k subarrays of length k. Slicing and checking whether one such subarray can be cyclically rotated into its target subarray takes O(k) time. Thus, checking one divisor takes O(
/// (n/k .(k)) =O(n) time, and checking all divisors takes O(n(sqrt(n)) time.
///
/// In addition, sorting nums takes O(nlogn) time, and finding all divisors of n takes O(sqrt(n))
///  ) time. Both terms are asymptotically smaller than O(n(sqrt(n)) and are therefore omitted from the final complexity.
///
/// Space complexity: O(n).
///
/// The target array and the KMP algorithm require O(n) space. Slicing and array concatenation in the code also require O(n) temporary space.
class Solution
{
public:
    int sortableIntegers(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> fac;

        for (int x = 1; x * x <= n; ++x)
        {
            if (n % x == 0)
            {
                fac.push_back(x);
                if (n / x != x)
                {
                    fac.push_back(n / x);
                }
            }
        }

        vector<int> target = nums;
        // ranges::sort(target);
        sort(target.begin(), target.end());

        auto kmp = [](const vector<int> &nums1, const vector<int> &nums2)
        {
            int n = nums1.size(), m = nums2.size();
            vector<int> pi(m, 0);
            int j = 0;

            for (int i = 1; i < m; ++i)
            {
                while (j > 0 && nums2[i] != nums2[j])
                {
                    j = pi[j - 1];
                }
                if (nums2[i] == nums2[j])
                {
                    ++j;
                }
                pi[i] = j;
            }

            j = 0;
            for (int i = 0; i < n; ++i)
            {
                while (j > 0 && nums1[i] != nums2[j])
                {
                    j = pi[j - 1];
                }
                if (nums1[i] == nums2[j])
                {
                    ++j;
                }
                if (j == m)
                {
                    return true;
                }
            }
            return false;
        };

        auto check = [&](const vector<int> &nums1, const vector<int> &nums2)
        {
            // Check whether cyclic rotations of nums1 can produce nums2
            vector<int> doubled = nums1;
            doubled.insert(doubled.end(), nums1.begin(), nums1.end());
            return kmp(doubled, nums2);
        };

        int ans = 0;

        for (int d : fac)
        {
            bool allGood = true;
            for (int left = 0; left < n; left += d)
            {
                int right = left + d - 1;
                vector<int> sub1(nums.begin() + left, nums.begin() + right + 1);
                vector<int> sub2(target.begin() + left,
                                 target.begin() + right + 1);

                if (!check(sub1, sub2))
                {
                    allGood = false;
                    break;
                }
            }
            if (allGood)
            {
                ans += d;
            }
        }

        return ans;
    }
};
// case analysis

/// Let n be the length of nums, and let k denote a divisor of n being checked.
///
/// Time complexity: O(n(sqrt(n))).
///
/// There are O(sqrt(n)) divisors of n. For each divisor k, nums is partitioned into
/// n / k subarrays of length k. Slicing and checking whether one such subarray can be cyclically rotated into its target subarray takes O(k) time. Thus, checking one divisor takes O(
/// (n/k .(k)) =O(n) time, and checking all divisors takes O(n(sqrt(n)) time.
///
/// In addition, sorting nums takes O(nlogn) time, and finding all divisors of n takes O(sqrt(n))
///  ) time. Both terms are asymptotically smaller than O(n(sqrt(n)) and are therefore omitted from the final complexity.
///
/// Space complexity: O(n).
///
/// The target array, along with slicing and array concatenation in the code, requires O(n) temporary space.
class SolutionI
{
public:
    int sortableIntegers(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> fac;

        for (int x = 1; x * x <= n; ++x)
        {
            if (n % x == 0)
            {
                fac.push_back(x);
                if (n / x != x)
                {
                    fac.push_back(n / x);
                }
            }
        }

        vector<int> target = nums;
        // ranges::sort(target);
        sort(target.begin(), target.end());

        // Check whether cyclic rotations of nums1 can produce nums2
        auto check = [](const vector<int> &nums1, const vector<int> &nums2)
        {
            int L = nums1.size();

            for (int i = 0; i < L - 1; ++i)
            {
                if (nums1[i] > nums1[i + 1])
                {
                    vector<int> rotated;
                    rotated.insert(rotated.end(), nums1.begin() + i + 1,
                                   nums1.end());
                    rotated.insert(rotated.end(), nums1.begin(),
                                   nums1.begin() + i + 1);
                    return rotated == nums2;
                }
            }

            return nums1 == nums2;
        };

        int ans = 0;

        for (int d : fac)
        {
            bool allGood = true;
            for (int left = 0; left < n; left += d)
            {
                int right = left + d - 1;

                vector<int> sub1(nums.begin() + left, nums.begin() + right + 1);
                vector<int> sub2(target.begin() + left,
                                 target.begin() + right + 1);

                if (!check(sub1, sub2))
                {
                    allGood = false;
                    break;
                }
            }
            if (allGood)
            {
                ans += d;
            }
        }

        return ans;
    }
};

int main()
{
    vector<int> nums = {1, 2, 5, 2, 3};
    Solution sol;
    int ans = sol.sortableIntegers(nums);
    cout << ans << endl;

    SolutionI solI;
    int ansI = solI.sortableIntegers(nums);
    cout << ansI << endl;

    return 0;
}