#include <bits/stdc++.h>
using namespace std;

// enumeration
/// Let n be the length of the string s.
///
/// Time complexity: O(n^3).
///
/// There are O(n) possible substring lengths, and for each length, we enumerate O(n) substrings. Checking the number of ones and extracting each substring both take O(n) time, resulting in a total time complexity of O(n^3).
///
/// Space complexity: O(n) or O(1).
///
/// At any time, we store a substring of length at most n and the current answer, both of which require O(n) space.

string shortestBeautifulSubstring(string s, int k)
{
    for (int m = k; m <= s.length(); m++)
    {
        string ans = "";
        for (int i = m; i <= s.length(); i++)
        {
            string t = s.substr(i - m, m);
            if ((ans.empty() || t < ans) && count(t.begin(), t.end(), '1') == k)
            {
                ans = t;
            }
        }
        if (!ans.empty())
        {
            return ans;
        }
    }
    return "";
}

// Sliding Window
/// Let n be the length of the string s.
///
/// Time complexity: O(n^2)
///
/// The sliding window itself takes O(n) time, since both left and right move from left to right at most once. However, extracting a substring takes O(n) time in the worst case, and this operation can be performed O(n) times. Therefore, the total time complexity is O(n^2).
///
/// Space complexity: O(n) or O(1).
///
/// The current substring and the answer can each require O(n) space.

string shortestBeautifulSubstringI(string s, int k)
{
    if (count(s.begin(), s.end(), '1') < k)
    {
        return "";
    }
    string ans = s;
    int cnt = 0;
    for (int left = 0, right = 0; right < s.length(); right++)
    {
        cnt += s[right] - '0';
        while (cnt > k || s[left] == '0')
        {
            cnt -= s[left] - '0';
            left++;
        }
        if (cnt == k)
        {
            string t = s.substr(left, right - left + 1);
            if (t.length() < ans.length() ||
                t.length() == ans.length() && t < ans)
            {
                ans = move(t);
            }
        }
    }
    return ans;
}

int main()
{

    string s = "1001011";
    int k = 3;
    cout << shortestBeautifulSubstring(s, k) << endl;
    cout << shortestBeautifulSubstringI(s, k) << endl;

    return 0;
}