#include <bits/stdc++.h>
using namespace std;

int minimumOperations(vector<int> &nums)
{
    int ops = 0;
    for (auto &i : nums)
    {
        if (i % 3 != 0)
            ops += 1;
    }

    return ops;
}

int main()
{

    vector<int> nums = {1, 2, 3, 4};
    cout << minimumOperations(nums) << endl;

    return 0;
}