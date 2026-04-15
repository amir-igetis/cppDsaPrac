#include <bits/stdc++.h>
using namespace std;

int minimumDistance(vector<int> &nums)
{
    int n = nums.size();
    int ans = n + 1;

    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            if (nums[i] != nums[j])
            {
                continue;
            }
            for (int k = j + 1; k < n; k++)
            {
                if (nums[j] == nums[k])
                {
                    ans = min(ans, k - i);
                    break;
                }
            }
        }
    }

    return ans == n + 1 ? -1 : ans * 2;
}

// optimal code using O(N)
int minimumDistanceI(vector<int> &nums)
{

    unordered_map<int, vector<int>> mp;

    // store indices for each value
    for (int i = 0; i < nums.size(); i++)
    {
        mp[nums[i]].push_back(i);
    }

    int ans = INT_MAX;

    // process each value
    for (auto &p : mp)
    {
        vector<int> &idx = p.second;

        // need at least 3 occurrences
        if (idx.size() < 3)
            continue;

        // check consecutive triplets
        for (int i = 0; i + 2 < idx.size(); i++)
        {
            int dist = 2 * (idx[i + 2] - idx[i]);
            ans = min(ans, dist);
        }
    }

    return (ans == INT_MAX) ? -1 : ans;
}

int main()
{
    vector<int> nums = {1, 2, 1, 1, 3};
    cout << minimumDistanceI(nums) << endl;

    return 0;
}