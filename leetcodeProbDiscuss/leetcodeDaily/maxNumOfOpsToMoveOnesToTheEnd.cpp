#include <bits/stdc++.h>
using namespace std;

int maxOperations(string s)
{
    int ones = 0, res = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '1')
            ones++;
        else if (i > 0 && s[i - 1] == '1')
            res += ones;
    }

    return res;
}

int main()
{

    string s = "1001101";
    cout << maxOperations(s) << endl;

    return 0;
}