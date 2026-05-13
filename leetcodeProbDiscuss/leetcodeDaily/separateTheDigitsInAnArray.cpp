#include <bits/stdc++.h>
using namespace std;

// simulation tc O(n logM) & sc O(logM)
vector<int> separateDigits(vector<int> &nums)
{
    vector<int> res;
    for (auto x : nums)
    {
        vector<int> tmp;
        while (x > 0)
        {
            tmp.push_back(x % 10);
            x /= 10;
        }
        for (int i = tmp.size() - 1; i >= 0; i--)
        {
            res.push_back(tmp[i]);
        }
    }
    return res;
}

// reverse Traversal tc O(n logM) & sc O(1)
vector<int> separateDigitsI(vector<int> &nums)
{
    vector<int> res;
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        int x = nums[i];
        while (x > 0)
        {
            res.push_back(x % 10);
            x /= 10;
        }
    }
    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    vector<int> nums = {13, 25, 83, 77};
    vector<int> ans = separateDigits(nums);
    for (auto &i : ans)
        cout << i << " ";
    cout << endl;

    return 0;
}