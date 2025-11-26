#include <bits/stdc++.h>
using namespace std;

vector<bool> prefixesDivBy5(vector<int> &nums)
{
    vector<bool> res;
    int val = 0;

    for (auto &bit : nums)
    {
        val = (val * 2 + bit) % 5;
        res.push_back(val == 0);
    }

    return res;
}

int main()
{

    vector<int> nums = {0, 1, 1};
    vector<bool> ans = prefixesDivBy5(nums);
    for (auto i : ans)
    {
        if (i == true)
            cout << "True" << " ";
        else
            cout << "False" << " ";
    }
    cout << endl;

    return 0;
}
