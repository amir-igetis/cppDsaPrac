#include <bits/stdc++.h>
using namespace std;

int numSub(string s)
{
    long long mod = 1e9 + 7;
    long long count = 0, res = 0;

    for (char ch : s)
    {
        if (ch == '1')
        {
            count++;
            res = (res + count) % mod;
        }
        else
        {
            count = 0;
        }
    }

    return (int)res;
}

int main()
{

    string s = "0110111";
    cout << numSub(s) << endl;

    return 0;
}