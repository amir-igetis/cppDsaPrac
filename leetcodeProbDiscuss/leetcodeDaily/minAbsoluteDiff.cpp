#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> minimumAbsDifference(vector<int> &arr)
{
    vector<vector<int>> res;
    sort(arr.begin(), arr.end());
    int minDiff = INT_MAX;
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        int currDiff = arr[i + 1] - arr[i];
        if (currDiff < minDiff)
            minDiff = currDiff;
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i + 1] - arr[i] == minDiff)
            res.push_back({arr[i], arr[i + 1]});
    }

    return res;
}

int main()
{

    vector<int> nums = {3, 8, -10, 23, 19, -4, -14, 27};
    vector<vector<int>> res = minimumAbsDifference(nums);

    for (auto &i : res)
    {
        for (auto &j : i)
            cout << j << " ";
        cout << endl;
    }
    cout << endl;

    return 0;
}