#include <bits/stdc++.h>
using namespace std;

int countBinarySubstrings(string s)
{
    int curr = 1, pre = 0, res = 0;
    for (int i = 1; i < s.length(); i++)
    {
        if (s[i] == s[i - 1])
            curr++;
        else
        {
            res += min(curr, pre);
            pre = curr;
            curr = 1;
        }
    }
    return res + min(curr, pre);
}

int main()
{
    string s = "00110011";
    cout << countBinarySubstrings(s) << endl;

    return 0;
}