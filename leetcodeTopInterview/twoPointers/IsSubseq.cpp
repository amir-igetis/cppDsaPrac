#include <bits/stdc++.h>
using namespace std;

// check other mothods too
bool isSubsequence(string s, string t)
{

    int i = 0, j = 0;
    while (i < s.length() && j < t.length())
    {
        if (s[i] == t[j])
            i++;

        j++;
    }

    if (i == s.size())
        return true;
    else
        return false;
}

int main()
{

    string s = "abc", t = "ahbgdc";
    cout << isSubsequence(s, t) << endl;

    return 0;
}