#include <bits/stdc++.h>
using namespace std;

// simulation

/// Let n be the length of the string.
///
/// Time complexity: O(n).
///
/// We traverse the string once.
///
/// Space complexity: O(1).
int reverseDegree(string s)
{
    int ans = 0;
    for (int i = 1; i <= s.length(); i++)
    {
        ans += (26 - (s[i - 1] - 'a')) * i;
    }
    return ans;
}

int main()
{
    string s = "abc";
    cout << reverseDegree(s) << endl;

    return 0;
}