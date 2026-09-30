#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k;
        cin >> n >> m >> k;

        vector<int> a(n + 1, 0);

        for (int i = 0; i < m; i++)
        {
            int x;
            cin >> x;
            a[x] = 1;
        }

        int avail = 0;
        for (int i = 1; i <= n && avail < k; i++)
        {
            if (a[i] == 0)
            {
                cout << i << " ";
                avail++;
            }
        }
        cout << "\n";
    }

    return 0;
}