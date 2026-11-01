#include <bits/stdc++.h>
using namespace std;

static int minMoves(vector<int> &nums)
{
    int lo = *min_element(nums.begin(), nums.end()), moves = 0;
    for (int x : nums)
        moves += x - lo;
    return moves;
}

/// Complexity
/// Time Complexity: O(N) where N is the size of the array. We iterate through the array exactly twice—once to find the minimum and once to calculate the total moves.
///
/// Space Complexity: O(1) as we only use a few integer variables to store the minimum value and the total moves.
int minMovesI(vector<int> &nums)
{
    int min = INT_MAX;

    // Step 1: Find the minimum element in the array
    for (int num : nums)
    {
        if (num < min)
        {
            min = num;
        }
    }

    // Step 2: Calculate the moves needed to bring every element down to the minimum
    int moves = 0;
    for (int num : nums)
    {
        moves += num - min;
    }

    return moves;
}

int main()
{
    vector<int> nums = {1, 2, 3};
    cout << minMoves(nums) << endl;
    cout << minMovesI(nums) << endl;

    return 0;
}
