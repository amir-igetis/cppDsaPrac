#include <bits/stdc++.h>
using namespace std;

int strStr(string haystack, string needle)
{
    int n = haystack.size(), m = needle.size();
    if (m == 0)
        return 0;

    for (int i = 0; i <= n - m; i++)
    {
        if (haystack.substr(i, m) == needle)
            return i;
    }

    return -1;
}

int main()
{
    string haystack = "sadbutsad";
    string needle = "but";
    cout << strStr(haystack, needle) << endl;

    return 0;
}
