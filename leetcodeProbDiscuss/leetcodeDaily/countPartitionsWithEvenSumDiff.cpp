#include <bits/stdc++.h>
using namespace std;

int countPartitions(vector<int> nums)
{
    int totalSum = 0;
    for (auto &i : nums)
        totalSum += i;

    return totalSum % 2 == 0 ? nums.size() - 1 : 0;
}

int main()
{
    vector<int> nums = {10, 10, 3, 7, 6};
    cout << countPartitions(nums) << endl;

    return 0;
}