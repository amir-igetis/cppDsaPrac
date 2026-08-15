#include <bits/stdc++.h>
using namespace std;

// enumerate the left endpoint
/// Let n be the length of s.
/// Time complexity: O(n^2)
///
/// Space complexity: O(1).
int maximumLengthSubstring(string s)
{
    int n = s.size();
    int res = 0;
    for (int left = 0; left < n; ++left)
    {
        array<int, 26> count{};
        for (int right = left; right < n; ++right)
        {
            const int index = s[right] - 'a';
            ++count[index];
            if (count[index] > 2)
            {
                break;
            }
            res = max(res, right - left + 1);
        }
    }
    return res;
}

// sliding window
/// Let n be the length of s.
///
/// Time complexity: O(n).
///
/// Each character is added to the sliding window at most once and removed from the sliding window at most once. Therefore, the overall time complexity is O(n).
///
/// Space complexity: O(1).
///
/// We use a fixed-size count array of size 26, so the extra space is O(1).
int maximumLengthSubstringI(string s)
{
    array<int, 26> count{};
    int left = 0;
    int res = 0;
    for (int right = 0; right < s.length(); ++right)
    {
        int ch = s[right] - 'a';
        ++count[ch];
        while (count[ch] > 2)
        {
            const int ch2 = s[left] - 'a';
            --count[ch2];
            ++left;
        }
        res = max(res, right - left + 1);
    }
    return res;
}

int main()
{
    string s = "abcabcabc";
    int result = maximumLengthSubstring(s);
    int res = maximumLengthSubstringI(s);
    cout << "Maximum length of substring with at most two occurrences of each character: " << result << endl;
    cout << "Maximum length of substring with at most two occurrences of each character using sliding window: " << res << endl;
    return 0;
}