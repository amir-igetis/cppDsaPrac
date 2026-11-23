#include <bits/stdc++.h>
using namespace std;

// Comparing Indices

/// Let n be the length of s.
///
/// Time complexity: O(n).
///
/// This is the time required to traverse the string and maintain the indices.
///
/// Space complexity: O(1).
///
/// Only a few variables are used, which requires constant extra space.
bool checkString(string s)
{
    int n = s.length();
    int lasta = -1; // Index of the last occurrence of 'a'
    int firstb = n; // Index of the first occurrence of 'b'
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == 'a')
        {
            lasta = max(lasta, i);
        }
        else
        {
            firstb = min(firstb, i);
        }
    }
    return lasta < firstb;
}

// Searching for a Substring

/// Let n be the length of s.
///
/// Time complexity: O(n).
///
/// This is the time required to traverse the string and search for a substring of length 2.
///
/// Space complexity: O(1).
///
/// Only constant extra space is used for the substring search.
bool checkStringI(string s)
{
    return s.find("ba") == string::npos;
}

int main()
{
    string s = "aaabbb";
    bool result = checkString(s);
    bool ans = checkStringI(s);
    cout << result << endl;
    cout << ans << endl;

    return 0;
}