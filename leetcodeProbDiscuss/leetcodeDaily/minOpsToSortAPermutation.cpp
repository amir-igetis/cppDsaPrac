#include <bits/stdc++.h>
using namespace std;

// simulation

/// Let n be the length of nums.
///
/// Time complexity: O(n).
///
/// Finding the index of 0 and verifying whether nums is cyclically increasing or decreasing each takes O(n) time. The minimum operations calculation takes O(1) time. Thus, the total time complexity is O(n).
///
/// Space complexity: O(1).
///
/// We use only a constant number of auxiliary variables.
class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        const int n = nums.size();
        if (n == 1)
        {
            return 0;
        }

        const int start = find(nums.begin(), nums.end(), 0) - nums.begin();
        bool asc = true;
        bool desc = true;

        for (int i = 1; i < n; i++)
        {
            const int value = nums[(start + i) % n];

            if (value != i)
            {
                asc = false;
            }
            if (value != n - i)
            {
                desc = false;
            }

            if (!asc && !desc)
            {
                return -1;
            }
        }

        if (asc)
        {
            return min(start, n - start + 2);
        }

        return min(n - start, start + 2);
    }
};

int main()
{
    vector<int> nums = {0, 2, 1};
    Solution sol;
    cout << sol.minOperations(nums) << endl;

    return 0;
}