#include <bits/stdc++.h>
using namespace std;

// Classification Discussion

/// Let n be the length of the array nums_1
///
/// Time complexity: O(n).
///
/// We only need to traverse the array once to find the minimum value and to determine if there is an odd number.
///
/// Space complexity: O(1).
///
/// Use only constant extra space.
bool uniformArray(vector<int> &nums1)
{
    int mn = nums1[0];
    bool hasOdd = false;
    for (int v : nums1)
    {
        if (v < mn)
        {
            mn = v;
        }
        if (v & 1)
        {
            hasOdd = true;
        }
    }
    if (mn & 1)
    {
        return true;
    }
    return !hasOdd;
}

int main()
{
    vector<int> nums1 = {1, 4, 7};
    cout << (uniformArray(nums1) ? "true" : "false") << endl;

    return 0;
}