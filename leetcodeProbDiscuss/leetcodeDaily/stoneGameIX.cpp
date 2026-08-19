#include <bits/stdc++.h>
using namespace std;

// construction
/// Let n be the length of the array stones.
///
/// Time complexity: O(n).
/// 
/// Space complexity: O(1).
bool stoneGameIX(vector<int> &stones)
{
    int cnt0 = 0, cnt1 = 0, cnt2 = 0;
    for (int val : stones)
    {
        int type = val % 3;
        if (type == 0)
        {
            ++cnt0;
        }
        else if (type == 1)
        {
            ++cnt1;
        }
        else
        {
            ++cnt2;
        }
    }
    if (cnt0 % 2 == 0)
    {
        return cnt1 >= 1 && cnt2 >= 1;
    }
    return cnt1 - cnt2 > 2 || cnt2 - cnt1 > 2;
}

int main()
{
    vector<int> stones = {2, 1};
    cout << (stoneGameIX(stones) ? "True" : "False") << endl; // Output: 1 (true)

    return 0;
}