#include <bits/stdc++.h>
using namespace std;

// Sorting approach
// Time: O(n log n)
// Space: O(1) (ignoring output string)
string smallestPalindrome(string s)
{
    int len = s.length();
    int partition = len / 2;

    sort(s.begin(), s.begin() + partition);

    for (int i = 0; i < partition; i++)
    {
        s[len - 1 - i] = s[i];
    }

    return s;
}

// Counting sort approach
// Time: O(n)
// Space: O(1)
string smallestPalindromeI(string s)
{
    int n = s.length();
    int partition = n / 2;

    vector<int> bucket(26, 0);

    // Count characters in the left half
    for (int i = 0; i < partition; i++)
    {
        bucket[s[i] - 'a']++;
    }

    string left = "";

    // Build the left half in sorted order
    for (int i = 0; i < 26; i++)
    {
        left.append(bucket[i], char('a' + i));
    }

    string mid = "";
    if (n % 2 == 1)
    {
        mid += s[partition];
    }

    string right = left;
    reverse(right.begin(), right.end());

    return left + mid + right;
}

int main()
{
    string s = "z";

    cout << smallestPalindrome(s) << endl;
    cout << smallestPalindromeI(s) << endl;

    return 0;
}