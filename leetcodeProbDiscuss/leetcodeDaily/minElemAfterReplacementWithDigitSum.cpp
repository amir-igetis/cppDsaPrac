#include <bits/stdc++.h>
using namespace std;

// math tc O(nlogd) & sc O(1)
int minElement(vector<int> &nums)
{
    int ans = 37;
    for (auto &num : nums)
    {
        int dig = 0;
        while (num > 0)
        {
            dig += num % 10;
            num /= 10;
        }
        ans = min(ans, dig);
    }
    return ans;
}

int main()
{
    vector<int> nums = {10, 12, 13, 14};
    cout << minElement(nums) << endl;

    return 0;
}
