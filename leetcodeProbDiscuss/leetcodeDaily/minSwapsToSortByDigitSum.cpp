#include <bits/stdc++.h>
using namespace std;

// permutation cycle

/// Let n be the length of the array nums, and M be the maximum value in the array.
///
/// Time complexity: O(nlogn+nlogM).
///
/// Calculating the digit sums takes O(nlogM), sorting takes O(nlogn), and traversing the permutation cycles takes O(n). The overall time complexity is O(nlogn+nlogM).
///
/// Space complexity: O(n).
///
/// We need four auxiliary arrays, digitSum, indices, targetPos, and visited, each taking O(n) space.
int minSwaps(vector<int> &nums)
{
    int n = nums.size();
    vector<int> digitSum(n);
    for (int i = 0; i < n; i++)
    {
        int x = nums[i], sum = 0;
        while (x > 0)
        {
            sum += x % 10;
            x /= 10;
        }
        digitSum[i] = sum;
    }

    vector<int> indices(n);
    iota(indices.begin(), indices.end(), 0);
    sort(indices.begin(), indices.end(), [&](int a, int b)
         {
            if (digitSum[a] != digitSum[b]) {
                return digitSum[a] < digitSum[b];
            }
            return nums[a] < nums[b]; });

    vector<int> targetPos(n);
    for (int pos = 0; pos < n; pos++)
    {
        targetPos[indices[pos]] = pos;
    }

    vector<int> visited(n);
    int cycles = 0;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            cycles++;
            int j = i;
            while (!visited[j])
            {
                visited[j] = true;
                j = targetPos[j];
            }
        }
    }

    return n - cycles;
}

// union-find

/// Let n be the length of the array nums, and M be the maximum value in the array.
///
/// Time complexity: O(nlogn+nlogM).
///
/// Calculating the digit sums takes O(nlogM), and sorting takes O(nlogn). The union-find operations use only path compression, without union by rank, and take O(nlogn) amortized time. The overall time complexity is O(nlogn+nlogM).
///
/// Space complexity: O(n).
///
/// We need four auxiliary arrays, digitSum, indices, targetPos, and parent, each taking O(n) space.

int minSwapsI(vector<int> &nums)
{
    int n = nums.size();
    vector<int> digitSum(n);
    for (int i = 0; i < n; i++)
    {
        int x = nums[i], sum = 0;
        while (x > 0)
        {
            sum += x % 10;
            x /= 10;
        }
        digitSum[i] = sum;
    }

    vector<int> indices(n);
    iota(indices.begin(), indices.end(), 0);
    sort(indices.begin(), indices.end(), [&](int a, int b)
         {
            if (digitSum[a] != digitSum[b]) {
                return digitSum[a] < digitSum[b];
            }
            return nums[a] < nums[b]; });

    vector<int> targetPos(n);
    for (int pos = 0; pos < n; pos++)
    {
        targetPos[indices[pos]] = pos;
    }

    vector<int> parent(n);
    iota(parent.begin(), parent.end(), 0);
    int components = n;

    function<int(int)> find = [&](int x) -> int
    {
        if (parent[x] != x)
        {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    };

    for (int i = 0; i < n; i++)
    {
        int ri = find(i);
        int rj = find(targetPos[i]);
        if (ri != rj)
        {
            parent[ri] = rj;
            components--;
        }
    }

    return n - components;
}

int main()
{

    vector<int> nums = {37, 100};
    cout << minSwaps(nums) << endl;
    cout << minSwapsI(nums) << endl;

    return 0;
}