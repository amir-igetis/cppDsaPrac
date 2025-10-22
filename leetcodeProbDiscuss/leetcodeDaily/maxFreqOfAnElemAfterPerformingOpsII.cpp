#include <bits/stdc++.h>
using namespace std;

int maxFrequency(vector<int> &nums, int k, int numOperations)
{
    const int n = nums.size();
    sort(nums.begin(), nums.end());
    int ans = 0, cnt = 0;
    int l = 0, r = 0;
    // Consider nums[i]
    for (int i = 0; i < n; i++)
    {
        const int x = nums[i], L = max(1, x - k), R = min(nums.back(), x + k);
        // count freq
        int f = 1;
        int j = i + 1;
        for (; j < n && nums[j] == x; j++)
            f++;
        i = j - 1; // nums[j]!=x // move l
        while (l < n && nums[l] < L)
            l++;             // move r
        r = (r > i) ? r : i; // start r from last position
        while (r + 1 < n && nums[r + 1] <= R)
            r++;
        cnt = r - l + 1;
        ans = max(ans, f + min(cnt - f, numOperations));
    } // consider the subintervals with overlapping
    for (l = 0, r = 0; r < n; r++)
    {
        int x = nums[r], L = max(1, x - 2 * k);
        while (l < r && nums[l] < L)
            l++;
        ans = max(ans, min(r - l + 1, numOperations));
    }
    return ans;
}

int maxFrequencyI(vector<int> &nums, int k, int numOperations)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());

    int maxFreq = 0;
    int left = 0;
    int right = 0;
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        int currentValue = nums[i];

        int leftRange = max(1, currentValue - k);
        int rightRange = min(nums.back(), currentValue + k);

        int freq = 1;
        int j = i + 1;

        while (j < n && nums[j] == currentValue)
        {
            freq++;
            j++;
        }

        i = j - 1;

        while (left < n && nums[left] < leftRange)
        {
            left++;
        }

        right = max(right, i);

        while (right + 1 < n && nums[right + 1] <= rightRange)
        {
            right++;
        }

        count = right - left + 1;
        int possibleFreq = freq + min(count - freq, numOperations);

        maxFreq = max(maxFreq, possibleFreq);
    }

    left = 0;
    right = 0;

    for (right = 0; right < n; right++)
    {
        int currentValue = nums[right];
        int minAllowed = max(1, currentValue - 2 * k);

        while (left < right && nums[left] < minAllowed)
        {
            left++;
        }

        int windowSize = right - left + 1;

        int possibleFreq = min(windowSize, numOperations);

        maxFreq = max(maxFreq, possibleFreq);
    }

    return maxFreq;
}

int main()
{

    vector<int> nums = {1, 4, 5};
    int k = 1, numOperarions = 2;

    cout << maxFrequency(nums, k, numOperarions) << endl;

    return 0;
}