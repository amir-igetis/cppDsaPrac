#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> &arr, vector<int> &arr2, int k)
{
    vector<int> res(k);
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> arr(n);
        vector<int> arr2(m);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        for (int i = 0; i < m; i++)
            cin >> arr2[i];

        vector<int> res = solve(arr, arr2, k);
        for (auto &i : res)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}
