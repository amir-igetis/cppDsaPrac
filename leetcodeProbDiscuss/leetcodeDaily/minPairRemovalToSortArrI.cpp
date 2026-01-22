#include <bits/stdc++.h>
using namespace std;

//    previous code

bool nonDec(const vector<int> &arr)
{
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] < arr[i - 1])
            return false;
    }
    return true;
}

int minimumPairRemovalII(vector<int> nums)
{
    int count = 0;

    while (!nonDec(nums))
    {
        int minSum = INT_MAX;
        int idx = -1;

        for (int i = 0; i + 1 < nums.size(); i++)
        {
            int sum = nums[i] + nums[i + 1];
            if (sum < minSum)
            {
                minSum = sum;
                idx = i;
            }
        }

        nums[idx] = minSum;
        nums.erase(nums.begin() + idx + 1);
        count++;
    }

    return count;
}

//    simulation tc and sc O(N^2) and O(1)

int minimumPairRemoval(vector<int> nums)
{
    int count = 0;

    while (nums.size() > 1)
    {
        bool isAscending = true;
        int minSum = INT_MAX;
        int target = -1;

        for (int i = 0; i + 1 < nums.size(); i++)
        {
            if (nums[i] > nums[i + 1])
                isAscending = false;

            int sum = nums[i] + nums[i + 1];
            if (sum < minSum)
            {
                minSum = sum;
                target = i;
            }
        }

        if (isAscending)
            break;

        nums[target] = minSum;
        nums.erase(nums.begin() + target + 1);
        count++;
    }

    return count;
}

//    simulation + Array Simulation of linked list tc O(n^2) and O(1)

int minimumPairRemovalI(vector<int> &nums)
{
    int n = nums.size();
    vector<int> next(n);
    for (int i = 0; i < n - 1; i++)
        next[i] = i + 1;
    next[n - 1] = -1;

    int count = 0;

    while (n - count > 1)
    {
        int curr = 0;
        int target = 0;
        int targetSum = nums[target] + nums[next[target]];
        bool isAscending = true;

        while (curr != -1 && next[curr] != -1)
        {
            if (nums[curr] > nums[next[curr]])
                isAscending = false;

            int sum = nums[curr] + nums[next[curr]];
            if (sum < targetSum)
            {
                targetSum = sum;
                target = curr;
            }
            curr = next[curr];
        }

        if (isAscending)
            break;

        nums[target] = targetSum;
        next[target] = next[next[target]];
        count++;
    }

    return count;
}

int main()
{
    vector<int> nums = {5, 2, 3, 1};
    cout << minimumPairRemovalI(nums) << endl;
    return 0;
}
