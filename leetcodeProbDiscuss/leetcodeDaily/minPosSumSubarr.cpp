#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <map>
#include <climits>

using namespace std;

class MinPosSumSubarr
{
public:
    // Brute Force
    // tc O(nr) sc O(1)
    static int minimumSumSubarray(const vector<int> &nums, int l, int r)
    {
        int n = nums.size(), best = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            int s = 0;
            for (int j = i; j < min(i + r, n); j++)
            { // nums[i..j], at most r long
                s += nums[j];
                if (j - i + 1 >= l && 0 < s && s < best)
                    best = s;
            }
        }
        return best == INT_MAX ? -1 : best;
    }

    // One Window Per Length
    // O(n⋅(r−l+1)) Time, O(1) Space.
    static int minimumSumSubarrayI(const vector<int> &nums, int l, int r)
    {
        int n = nums.size(), best = INT_MAX;
        for (int k = l; k <= r; k++)
        {
            int s = 0;
            for (int i = 0; i < k - 1 && i < n; i++)
            {
                s += nums[i];
            }
            for (int i = k - 1; i < n; i++)
            {
                s += nums[i]; // the window nums[i - k + 1 .. i]
                if (0 < s && s < best)
                    best = s;
                s -= nums[i - k + 1];
            }
        }
        return best == INT_MAX ? -1 : best;
    }

    // With prefix sums, every subarray is one subtraction.
    static int minimumSumSubarrayII(const vector<int> &nums, int l, int r)
    {
        int n = nums.size();
        vector<int> pre(n + 1, 0); // pre[i] = sum(nums[:i])
        for (int i = 0; i < n; i++)
        {
            pre[i + 1] = pre[i] + nums[i];
        }

        int best = INT_MAX;
        for (int k = l; k <= r; k++)
        {
            for (int i = 0; i <= n - k; i++)
            {
                int s = pre[i + k] - pre[i];
                if (s > 0 && s < best)
                {
                    best = s;
                }
            }
        }
        return best == INT_MAX ? -1 : best;
    }

    // Sorted Window of Starts
    // O(nlogn) Time and O(n) Space.
    static int minimumSumSubarrayIII(const vector<int> &nums, int l, int r)
    {
        int n = nums.size(), best = INT_MAX;
        vector<int> pre(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            pre[i + 1] = pre[i] + nums[i];
        }

        map<int, int> starts; // pre[i] -> how many starts that fit the end j have it
        for (int j = l; j <= n; j++)
        {
            starts[pre[j - l]]++; // start j - l: length l
            if (j > r)
            {
                int keyToRemove = pre[j - r - 1]; // start j - r - 1: length r + 1, too long
                starts[keyToRemove]--;
                if (starts[keyToRemove] == 0)
                {
                    starts.erase(keyToRemove);
                }
            }

            auto it = starts.lower_bound(pre[j]);
            if (it != starts.begin())
            {
                it--; // the largest pre[i] < pre[j]
                best = min(best, pre[j] - it->first);
            }
        }
        return best == INT_MAX ? -1 : best;
    }
};

int main()
{
    vector<int> nums = {3, -2, 1, 4};
    int l = 2;
    int r = 3;

    cout << MinPosSumSubarr::minimumSumSubarray(nums, l, r) << endl;
    cout << MinPosSumSubarr::minimumSumSubarrayI(nums, l, r) << endl;
    cout << MinPosSumSubarr::minimumSumSubarrayII(nums, l, r) << endl;
    cout << MinPosSumSubarr::minimumSumSubarrayIII(nums, l, r) << endl;

    return 0;
}