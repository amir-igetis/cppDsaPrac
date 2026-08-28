#include <bits/stdc++.h>
using namespace std;

// Enumeration + Hash Table
/// Let n be the length of the array nums.
///
/// Time complexity: O(n).
///
/// Constructing the hash set takes O(n) time. We may need to enumerate at most n+1 multiples of k, and each lookup takes O(1) average time.
///
/// Space complexity: O(n)
///
/// The hash set stores at most n distinct elements.

int missingMultiple(vector<int> &nums, int k)
{
    unordered_set<int> seen(nums.begin(), nums.end());
    int ans = k;
    while (seen.count(ans))
    {
        ans += k;
    }
    return ans;
}

int main()
{
    vector<int> nums = {8, 2, 3, 4, 6};
    int k = 2;
    cout << missingMultiple(nums, k) << endl;

    return 0;
}