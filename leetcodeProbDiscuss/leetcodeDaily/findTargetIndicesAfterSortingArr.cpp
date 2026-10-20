#include <bits/stdc++.h>
using namespace std;

// sort and traverse

/// Let n be the length of nums.
///
/// Time complexity: O(nlogn).
///
/// Sorting takes O(nlogn) time, and traversing the array to record the target indices takes O(n) time.
///
/// Space complexity: O(logn) or O(n).
///
/// Sorting algorithms typically require O(logn) auxiliary stack space (e.g., quicksort in C++ and Java) or up to O(n) space (e.g., Timsort in Python).
vector<int> targetIndices(vector<int> &nums, int target)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<int> res;
    for (int i = 0; i < n; ++i)
    {
        if (nums[i] == target)
        {
            res.push_back(i);
        }
    }
    return res;
}

// count directly

/// Let n be the length of nums.
///
/// Time complexity: O(n).
///
/// Traversing the array to count elements and constructing the answer array take O(n) time.
///
/// Space complexity: O(1).
///
/// The output array is not included in the space complexity.
vector<int> targetIndicesI(vector<int> &nums, int target)
{
    int cnt1 = 0; // Number of elements less than target
    int cnt2 = 0; // Number of elements equal to target
    for (const int num : nums)
    {
        if (num < target)
        {
            ++cnt1;
        }
        else if (num == target)
        {
            ++cnt2;
        }
    }
    vector<int> res; // Array of indices
    for (int i = cnt1; i < cnt1 + cnt2; ++i)
    {
        res.push_back(i);
    }
    return res;
}

int main()
{
    vector<int> nums = {1, 2, 5, 2, 3};
    int target = 2;
    vector<int> res1 = targetIndices(nums, target);
    vector<int> res2 = targetIndicesI(nums, target);
    for (int i : res1)
    {
        cout << i << " ";
    }
    cout << endl;
    for (int i : res2)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}