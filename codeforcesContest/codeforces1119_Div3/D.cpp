#include <bits/stdc++.h>
using namespace std;

string func(int n, vector<int> &a)
{
    vector<int> count(n + 2, 0);

    for (int i = 0; i < n; i++)
        if (a[i] <= n)
            count[a[i]]++;

    if (count[0] == 0)
        return "YES\n" + string(n, 'A');

    if (count[0] == 1)
        return "NO";

    int x = 0, y = 0, z = 0;
    while (count[x] >= 1)
        x++;
    while (count[y] >= 2)
        y++;
    while (count[z] >= 3)
        z++;

    int T = min(x, y + z);

    vector<bool> hasA(n + 2, false);
    vector<bool> hasB(n + 2, false);
    vector<bool> hasC(n + 2, false);

    string ans = "";

    for (int i = 0; i < n; i++)
    {
        int E = a[i];

        if (E > n)
        {
            ans += 'C';
            continue;
        }

        if (E < T && !hasA[E])
        {
            ans += 'A';
            hasA[E] = true;
        }
        else if (E < y && !hasB[E])
        {
            ans += 'B';
            hasB[E] = true;
        }
        else if (E < z && !hasC[E])
        {
            ans += 'C';
            hasC[E] = true;
        }
        else
            ans += 'C';
    }
    return "YES\n" + ans;
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
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        cout << func(n, a) << endl;
    }
    return 0;
}