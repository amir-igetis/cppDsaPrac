#include <bits/stdc++.h>
using namespace std;

bool canBeEqual(string s1, string s2)
{

    return ((s1[0] == s2[0] && s1[2] == s2[2]) ||
            (s1[0] == s2[2] && s1[2] == s2[0])) &&
           ((s1[1] == s2[1] && s1[3] == s2[3]) ||
            (s1[1] == s2[3] && s1[3] == s2[1]));
}

int main()
{
    string s1 = "abcd", s2 = "cdab";
    cout << (canBeEqual(s1, s2) ? "True" : "False") << endl;

    return 0;
}