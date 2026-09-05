#include <bits/stdc++.h>
using namespace std;

int func(int n, vector<int> &a)
{

    int odd = 0, evenMod4 = 0, evenMod2 = 0;
    for (int i = 0; i < n; i++)
    {

        if (a[i] % 2 != 0)
            odd++;
        else if (a[i] % 4 == 0)
            evenMod4++;
        else
            evenMod2++;
    }
    return max({odd, evenMod4, evenMod2});
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
        cout << func(n, a) << endl;
    }

    return 0;
}