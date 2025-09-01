#include <bits/stdc++.h>
using namespace std;

void backtrack(vector<vector<int>> &res, vector<int> &curr, vector<int> &candidates, int target, int start)
{
    if (target == 0)
    {
        res.push_back(curr);
        return;
    }

    if (target < 0)
        return;

    for (int i = start; i < candidates.size(); i++)
    {
        curr.push_back(candidates[i]);
        backtrack(res, curr, candidates, target - candidates[i], i);
        curr.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{

    vector<vector<int>> res;
    vector<int> curr;
    backtrack(res, curr, candidates, target, 0);
    return res;
}

int main()
{

    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    vector<vector<int>> ans = combinationSum(candidates, target);

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