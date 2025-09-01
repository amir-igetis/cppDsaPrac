#include <bits/stdc++.h>
using namespace std;

void backtrack(vector<vector<int>> &res, vector<int> &curr, vector<int> &nums, vector<bool> &used)
{
    if (curr.size() == nums.size())
    {
        res.push_back(curr);
        return;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (used[i])
            continue;

        curr.push_back(nums[i]);
        used[i] = true;
        backtrack(res, curr, nums, used);
        curr.pop_back();
        used[i] = false;
    }
}

vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> res;
    vector<bool> used(nums.size());
    vector<int> curr;
    backtrack(res, curr, nums, used);
    return res;
}

int main()
{

    vector<int> nums = {1, 2, 3};

    vector<vector<int>> ans = permute(nums);

    for (auto &i : ans)
    {
        for (int j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}