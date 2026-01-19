#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> &arr, vector<vector<int>> &arr2, int h)
{
    vector<int> array = arr;
    vector<int> curr = arr;
    for (auto &i : arr2)
    {
        int bi = i[0] - 1;
        int ci = i[1];

        curr[bi] = curr[bi] + ci;
        if (curr[bi] > h)
            curr = array;
    }

    return curr;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n, m, h;
        cin >> n >> m >> h;
        vector<int> arr(n);
        vector<vector<int>> arr2(m, vector<int>(2));
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        for (int i = 0; i < m; i++)
        {
            cin >> arr2[i][0] >> arr2[i][1];
        }
        vector<int> res = solve(arr, arr2, h);
        for (auto &i : res)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}
