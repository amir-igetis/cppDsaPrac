#include <bits/stdc++.h>
using namespace std;

void func(int n)
{
    for (int i = 1; i <= n; i++)
    {
        cout << i << " ";
    }
    cout << "\n";
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
        string s;
        cin >> n;
        func(n);

        // vector<int> res = func(n, s);
        // // cout << func(n, s) << endl;

        // for (auto &i : res)
        // {
        //     cout << i << " ";
        // }
        // cout << endl;
    }

    return 0;
}
