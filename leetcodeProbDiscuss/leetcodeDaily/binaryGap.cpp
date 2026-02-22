#include <bits/stdc++.h>
using namespace std;

int binaryGap(int n)
{
    int last = -1;
    int ans = 0;
    int pos = 0;
    while (n > 0)
    {
        if (n & 1)
        {
            if (last != -1)
                ans = max(ans, pos - last);

            last = pos;
        }
        n >>= 1;
        pos++;
    }
    return ans;
}

int main()
{
    int n = 22;
    cout << binaryGap(n) << endl;

    return 0;
}