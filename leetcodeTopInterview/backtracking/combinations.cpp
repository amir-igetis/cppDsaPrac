#include <bits/stdc++.h>
using namespace std;

void backtrack(vector<vector<int>> &res, vector<int> &curr, int start, int n, int k)
{
    if (curr.size() == k)
    {
        res.push_back(curr);
        return;
    }

    for (int i = start; i <= n; i++)
    {
        curr.push_back(i);
        backtrack(res, curr, i + 1, n, k);
        curr.pop_back();
    }
}

vector<vector<int>> combine(int n, int k)
{
    vector<vector<int>> res;
    vector<int> curr;
    backtrack(res, curr, 1, n, k);
    return res;
}

int main()
{

    int n = 4, k = 2;

    vector<vector<int>> ans = combine(n, k);

    cout << "Combinations:" << endl;
    for (auto &comb : ans)
    {
        cout << "[";
        for (int i = 0; i < comb.size(); i++)
        {
            cout << comb[i] << (i + 1 < comb.size() ? "," : "");
        }
        cout << "]" << endl;
    }

    return 0;
}