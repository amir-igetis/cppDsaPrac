#include <bits/stdc++.h>
using namespace std;

// greedy + sorting

/// Let n be the length of the array nums.
///
/// Time complexity: O(nlogn).
///
/// Squaring each element takes O(n) time, sorting the array takes O(nlogn) time, and summing the elements takes O(n) time. Thus, the overall time complexity is dominated by sorting: O(nlogn).
///
/// Note: If quickselect or std::nth_element is used to partition the elements around the median instead of fully sorting, an average time complexity of O(n) can be achieved.
///
/// Space complexity: O(n) or O(logn).
///
/// The space complexity depends on the programming language and sorting implementation:
///
/// In Python, nums.sort() uses Timsort, which takes O(n) auxiliary space. In addition, slicing nums creates new lists consuming O(n) extra space.
/// In C++, Java, and Go, in-place sorting algorithms typically require O(logn) auxiliary stack space for recursion.
long long maxAlternatingSum(vector<int> &nums)
{
    int n = nums.size();
    for (auto &num : nums)
    {
        num *= num;
    }
    sort(nums.begin(), nums.end());
    return -accumulate(nums.begin(), nums.begin() + n / 2, 0LL) +
           accumulate(nums.begin() + n / 2, nums.end(), 0LL);
}

int main()
{
    vector<int> nums = {1, 2, 3};
    long long result = maxAlternatingSum(nums);
    cout << "Max Alternating Sum of Squares: " << result << endl;
    return 0;
}