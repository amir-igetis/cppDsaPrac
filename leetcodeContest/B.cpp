#include <bits/stdc++.h>
using namespace std;

vector<long long> mergeAdjacent(vector<int> &nums)
{
    int n = nums.size();
    vector<long long> ans;
    if (nums.empty())
        return {};
    ans[0] = nums[0];
    int j = 0;
    for (int i = 1; i < n; i++)
    {
        if (ans[j] == nums[i])
        {
            ans[j] = 2 * nums[i];
        }
        else
        {

            ans[j + 1] = nums[i];
            j++;
        }
    }
    return ans;
}

vector<long long> mergeAdjacentI(vector<int> &nums)
{
    vector<long long> ans(nums.begin(), nums.end());
    while (true)
    {
        vector<long long> temp;
        bool merged = false;
        int i = 0;
        while (i < ans.size())
        {
            if (i + 1 < ans.size() && ans[i] == ans[i + 1])
            {
                temp.push_back(ans[i] * 2);
                i += 2;
                merged = true;
            }
            else
            {
                temp.push_back(ans[i]);
                i++;
            }
        }
        if (!merged)
            break;
        ans = temp;
    }
    return ans;
}

int main()
{
    vector<int> nums = {3, 1, 1, 2};
    vector<int> numsI = {2, 2, 4};
    vector<int> numsII = {2, 1, 1, 2};

    vector<long long> ans = mergeAdjacentI(numsII);
    for (auto &i : ans)
        cout << i << " ";
    cout << endl;

    return 0;
}