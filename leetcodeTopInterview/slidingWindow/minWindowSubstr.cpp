#include <bits/stdc++.h>
using namespace std;

string minWindow(string s, string t)
{
    vector<int> freq(128);
    for (char c : t)
        freq[c]++;

    int left = 0, right = 0, required = t.size(),
        formed = 0, minLen = INT_MAX, minLeft = 0, minRight = 0;

    while (right < s.size())
    {
        char c = s[right];
        freq[c]--;

        if (freq[c] >= 0)
            formed++;

        while (formed == required)
        {
            if (right - left + 1 < minLen)
            {
                minLen = right - left + 1;
                minLeft = left;
                minRight = right;
            }
            freq[s[left]]++;

            if (freq[s[left]] > 0)
                formed--;

            left++;
        }
        right++;
    }

    return minLen == INT_MAX ? "" : s.substr(minLeft, minRight + 1);
}

int main()
{

    string s = "ADOBECODEBANC", t = "ABC";
    cout << minWindow(s, t) << endl;

    return 0;
}