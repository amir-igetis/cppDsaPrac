#include <bits/stdc++.h>
using namespace std;

// Classification Discussion
/// Let n be the length of nums.
///
/// Time complexity: O(n).
///
/// We traverse the array once to find the indices of the minimum and maximum values.
///
/// Space complexity: O(1).
int minimumDeletions(vector<int> &nums)
{
    int n = nums.size();
    int minidx = min_element(nums.begin(), nums.end()) - nums.begin();
    int maxidx = max_element(nums.begin(), nums.end()) - nums.begin();
    int l = min(minidx,
                maxidx); // The smaller value in the most valuable index
    int r =
        max(minidx, maxidx); // The bigger value in the most valuable index
    return min(
        {r + 1, n - l, l + 1 + n - r}); // Calculate the minimum number of
                                        // deletions in three cases
}

int main()
{

    vector<int> nums = {0, -4, 19, 1, 8, -2, -3, 5};
    cout << minimumDeletions(nums) << endl;

    return 0;
}