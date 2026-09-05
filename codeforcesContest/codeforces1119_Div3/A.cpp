#include <bits/stdc++.h>
using namespace std;

int func(string s, int n, int k)
{
    int ans = 0, oneInFarm = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            oneInFarm++;
        }

        if ((i + 1) % k == 0)
        {
            if (oneInFarm == k)
            {
                ans++;
            }
            oneInFarm = 0;
        }
    }
    return ans;
}

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        cout << func(s, n, k) << endl;
    }

    return 0;
}