#include <bits/stdc++.h>
using namespace std;

int maxSumDivThree(vector<int> &nums)
{
    int sum = 0;
    vector<int> rem1, rem2;

    for (int x : nums)
    {
        sum += x;
        if (x % 3 == 1)
            rem1.push_back(x);
        else if (x % 3 == 2)
            rem2.push_back(x);
    }

    sort(rem1.begin(), rem1.end());
    sort(rem2.begin(), rem2.end());

    if (sum % 3 == 0)
        return sum;

    int ans = 0;

    if (sum % 3 == 1)
    {
        int remove1 = rem1.size() > 0 ? rem1[0] : INT_MAX;
        int remove2 = rem2.size() > 1 ? rem2[0] + rem2[1] : INT_MAX;
        ans = sum - min(remove1, remove2);
    }

    if (sum % 3 == 2)
    {
        int remove1 = rem2.size() > 0 ? rem2[0] : INT_MAX;
        int remove2 = rem1.size() > 1 ? rem1[0] + rem1[1] : INT_MAX;
        ans = sum - min(remove1, remove2);
    }

    return ans < 0 ? 0 : ans;
}

int main()
{

    vector<int> nums = {3, 6, 5, 1, 8};
    cout << maxSumDivThree(nums) << endl;

    return 0;
}