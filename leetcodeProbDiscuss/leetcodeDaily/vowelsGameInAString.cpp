#include <bits/stdc++.h>
using namespace std;

bool doesAliceWin(string s)
{
    for (char c : s)
    {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        {
            return true;
        }
    }
    return false;
}

int main()
{

    string s = "leetcoder";

    cout << (doesAliceWin(s) ? "True" : "False") << endl;

    return 0;
}