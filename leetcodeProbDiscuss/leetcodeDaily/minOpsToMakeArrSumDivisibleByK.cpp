#include <bits/stdc++.h>
using namespace std;

int minOperations(vector<int> &nums, int k)
{
    long long sum = 0;
    for (auto &x : nums)
        sum += x;

    int rem = sum % k;

    return rem;
}

int main()
{

    vector<int> nums = {3, 9, 7};
    int k = 5;
    cout << minOperations(nums, k) << endl;

    return 0;
}