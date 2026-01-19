#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr)
{
    int maxi = 0;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, arr[i]);
    }
    return n * maxi;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);

        for (int i = 0; i < n; i++)
            cin >> arr[i];

        cout << solve(arr) << endl;
    }

    return 0;
}