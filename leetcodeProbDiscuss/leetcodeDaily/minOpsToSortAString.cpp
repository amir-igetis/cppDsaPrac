#include <bits/stdc++.h>
using namespace std;

// case analysis

/// Let n be the length of the string s.
///
/// Time complexity: O(n).
///
/// Checking whether s is sorted and finding the minimum and maximum characters takes O(n) time. Scanning the middle of the string takes at most O(n) time.
///
/// Space complexity: O(1).
///
/// Only a constant number of auxiliary variables are used.
int minOperations(string s)
{
    char mx = 'a', mn = 'z';
    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        mx = max(mx, s[i]);
        mn = min(mn, s[i]);
    }
    // if (ranges::is_sorted(s))
    if (is_sorted(s.begin(), s.end()))
    {
        return 0;
    }
    if (n == 2)
    {
        return -1;
    }
    if (s[0] == mn || s[n - 1] == mx)
    {
        return 1;
    }
    for (int i = 1; i < n - 1; i++)
    {
        if (s[i] == mn || s[i] == mx)
        {
            return 2;
        }
    }
    return 3;
}

int main()
{
    string s = "dog";
    cout << minOperations(s) << endl;

    return 0;
}