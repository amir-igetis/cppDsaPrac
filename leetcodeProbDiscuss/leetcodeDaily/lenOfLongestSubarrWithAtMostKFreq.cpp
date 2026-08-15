#include <bits/stdc++.h>
using namespace std;

// Counting and Sliding Window
/// Let N be the length of nums.
///
/// Time complexity: O(N).
///
/// The outer loop iterates through each element in the array exactly once, as indicated by the range from 0 to the length of nums in the for loop.
/// Inside this loop, the while loop with the start pointer performs a sliding window operation. However, note that the start pointer is increased and frequency[nums[start]] is decreased within this loop. The start pointer is never decreased after it is increased in the while loop. Hence, once an element is processed in the while loop, it will not be revisited. Therefore, each element is processed at most twice: once during the outer loop and at most once during the while loop.
/// In the worst case, the while loop could iterate through the entire length of the array during its lifetime. However, since each element is processed at most twice, the total number of iterations across all elements is linear, making the time complexity of the algorithm O(N).
/// Space complexity: O(N). The data structure used to store frequency incurs a space complexity of O(N), since in the worst case the array nums can have all unique elements.
int maxSubarrayLength(vector<int> &nums, int k)
{
    int ans = 0, start = -1;
    unordered_map<int, int> frequency;

    for (int end = 0; end < nums.size(); end++)
    {
        frequency[nums[end]]++;
        while (frequency[nums[end]] > k)
        {
            start++;
            frequency[nums[start]]--;
        }
        ans = max(ans, end - start);
    }

    return ans;
}

// Counting and Sliding Window without Nested Loops
/// Let N be the length of nums.
///
/// Time complexity: O(N). We perform one pass over the given array nums. This incurs a time complexity of O(N).
///
/// Space complexity: O(N). The data structure used to store frequency incurs a space complexity of O(N) since, in the worst case, the array nums can have all unique elements.

int maxSubarrayLengthI(vector<int> &nums, int k)
{
    int n = nums.size();
    unordered_map<int, int> frequency;
    int start = 0;
    int charsWithFreqOverK = 0;

    for (int end = 0; end < n; end++)
    {
        frequency[nums[end]]++;
        if (frequency[nums[end]] == k + 1)
        {
            charsWithFreqOverK++;
        }
        if (charsWithFreqOverK > 0)
        {
            frequency[nums[start]]--;
            if (frequency[nums[start]] == k)
            {
                charsWithFreqOverK--;
            }
            start++;
        }
    }
    return n - start;
}

int main()
{
    vector<int> nums = {1, 2, 3, 1, 2, 3, 1, 2};
    int k = 2;
    cout << maxSubarrayLength(nums, k) << endl;
    cout << maxSubarrayLengthI(nums, k) << endl;

    return 0;
}