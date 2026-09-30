#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    if (cin >> t)
    {
        while (t--)
        {
            int n;
            cin >> n;

            vector<int> a(n);
            for (int i = 0; i < n; i++)
            {
                int val;
                cin >> val;
                a[i] = val - i;
            }
            sort(a.begin(), a.end());

            int maxFreq = 1;
            int currFreq = 1;

            for (int i = 1; i < n; i++)
            {
                if (a[i] == a[i - 1])
                    currFreq++;
                else
                {
                    maxFreq = max(maxFreq, currFreq);
                    currFreq = 1;
                }
            }
            maxFreq = max(maxFreq, currFreq);
            cout << n - maxFreq << "\n";
        }
    }
    return 0;
}