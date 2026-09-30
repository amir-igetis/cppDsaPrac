#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> freq(105, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] <= 101)
        {
            freq[a[i]]++;
        }
    }

    int mex = 0;
    while (freq[mex] > 0)
    {
        mex++;
    }

    long long totalMoves = 0;
    long long sumLessThanMex = 0;

    for (int x : a)
    {
        if (x > mex)
        {
            totalMoves += (x - mex - 1);
        }
        else if (x < mex)
        {
            sumLessThanMex += x;
        }
    }
    long long requiredSum = (long long)mex * (mex - 1) / 2;
    totalMoves += (sumLessThanMex - requiredSum);
    if (totalMoves % 2 != 0)
    {
        cout << "Alice\n";
    }
    else
    {
        cout << "Bob\n";
    }
}

int main()
{
    int t;
    if (cin >> t)
    {
        while (t--)
        {
            solve();
        }
    }
    return 0;
}