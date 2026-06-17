#include <bits/stdc++.h>
using namespace std;

//    simulation tc & sc O(2^n)
string processStr(string s)
{
    string res;
    for (auto &ch : s)
    {
        if (ch == '*')
        {
            if (res.length() > 0)
                res.pop_back();
        }
        else if (ch == '#')
            res += res;
        else if (ch == '%')
            res = string(res.rbegin(), res.rend());
        else
            res += ch;
    }
    return res;
}

int main()
{
    string s = "a#b%*";
    cout << processStr(s) << endl;

    return 0;
}