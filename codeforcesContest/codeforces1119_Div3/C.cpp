#include <bits/stdc++.h>
using namespace std;

void func(int n, vector<int> &a)
{

    int firstOne = -1, lastOne = -1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != 0)
        {
            if (firstOne == -1)
                firstOne = i;
            lastOne = i;
        }
    }

    if (firstOne != -1 && a[firstOne] == -1)
        a[firstOne] = 1;

    if (lastOne != -1 && a[lastOne] == -1)
        a[lastOne] = 1;

    for (int i = 0; i < n; i++)
    {
        if (a[i] == -1)
            a[i] = 0;
        cout << a[i] << (i == n - 1 ? "" : " ");
    }
    cout << endl;
}

int main()
{
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
        func(n, a);
    }

    return 0;
}