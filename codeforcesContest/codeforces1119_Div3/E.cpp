#include <bits/stdc++.h>
using namespace std;

string func(int n, vector<int> &b)
{
    vector<int> diff(n + 1, 0);

    for (int i = 0; i < n; i++)
    {
        if (b[i] != -1)
        {
            int L = max(0, i - b[i] + 1);
            int R = min(n - 1, i + b[i] - 1);
            if (L <= R)
            {
                diff[L]++;
                diff[R + 1]--;
            }
        }
    }
    string treasureMapFin = "";
    int currZeros = 0;
    bool hasTreasure = false;

    for (int i = 0; i < n; i++)
    {
        currZeros += diff[i];
        if (currZeros > 0)
            treasureMapFin += '0';
        else
        {
            treasureMapFin += '1';
            hasTreasure = true;
        }
    }
    if (!hasTreasure)
        return "-1";

    for (int i = 0; i < n; i++)
    {
        if (b[i] != -1)
        {
            int L = i - b[i];
            int R = i + b[i];
            bool ok = false;

            if (L >= 0 && L < n && treasureMapFin[L] == '1')
                ok = true;

            if (R >= 0 && R < n && treasureMapFin[R] == '1')
                ok = true;

            if (!ok)
                return "-1";
        }
    }

    return treasureMapFin;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> b(n);
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        cout << func(n, b) << endl;
    }
    return 0;
}