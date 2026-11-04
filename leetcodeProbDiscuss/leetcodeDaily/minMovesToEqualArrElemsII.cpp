#include <bits/stdc++.h>
using namespace std;

// Sorting

/// Time Complexity: O(N log N) due to the sorting step.
///
/// Space Complexity: O(1) (or O(log N) depending on the sorting algorithm implementation under the hood of Arrays.sort).

int minMoves(vector<int> &nums)
{
    sort(nums.begin(), nums.end());

    int moves = 0;
    int left = 0;
    int right = nums.size() - 1;

    while (left < right)
    {
        moves += nums[right] - nums[left];
        left++;
        right--;
    }

    return moves;
}

// Quickselect

/// Time Complexity: O(N) on average to find the median, followed by an O(N) pass to calculate moves. The worst-case is O(N^2) if the array is already sorted and a poor pivot is chosen, though randomized pivoting can prevent this.
///
/// Space Complexity: O(1) auxiliary space (or O(log N) call stack space due to recursion).

int minMoves2(vector<int> &nums)
{
    int n = nums.size();

    // Find the median in O(N) time
    auto middle = nums.begin() + n / 2;
    nth_element(nums.begin(), middle, nums.end());
    int median = *middle;

    long long moves = 0; // Using long long to prevent overflow during sum, though constraints fit in 32-bit
    for (int num : nums)
    {
        moves += abs(num - median);
    }

    return moves;
}

int main()
{
    vector<int> nums = {1, 2, 3};
    cout << minMoves(nums) << endl;
    cout << minMoves2(nums) << endl;

    return 0;
}