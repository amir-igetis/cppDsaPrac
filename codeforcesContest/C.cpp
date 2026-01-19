#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr)
{
    sort(arr.begin(), arr.end());
    int seq = 1;
    int curr = 1;
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] == arr[i - 1])
            continue;
        else if (arr[i] == arr[i - 1] + 1)
            curr++;
        else
        {
            seq = max(seq, curr);
            curr = 1;
        }
    }
    seq = max(seq, curr);
    return seq;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

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
