#include <bits/stdc++.h>
using namespace std;

int maxFrequency(vector<int> &nums, int k, int numOperations)
{
    int maxVal = *max_element(nums.begin(), nums.end()) + k + 2;
    int *count = new int[maxVal]();

    for (int v : nums)
        count[v]++;

    for (int i = 1; i < maxVal; i++)
        count[i] += count[i - 1];

    int res = 0;
    for (int i = 0; i < maxVal; i++)
    {
        int left = max(0, i - k);
        int right = min(maxVal - 1, i + k);
        int total = count[right] - (left ? count[left - 1] : 0);
        int freq = count[i] - (i ? count[i - 1] : 0);
        res = max(res, freq + min(numOperations, total - freq));
    }

    return res;
}

int main()
{

    vector<int> nums = {5, 11, 20, 20};
    int k = 5, numOperations = 1;
    cout << maxFrequency(nums, k, numOperations);

    return 0;
}