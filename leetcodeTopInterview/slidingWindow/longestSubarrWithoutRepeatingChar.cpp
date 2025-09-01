#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s)
{
    set<char> st;
    int left = 0, right = 0, maxLen = 0;
    for (; right < s.size(); right++)
    {
        while (st.find(s[right]) != st.end())
        {
            st.erase(s[left]);
            left++;
        }
        st.insert(s[right]);
        maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;
}

int main()
{

    string s = "pwwkew";
    cout << lengthOfLongestSubstring(s) << endl;

    return 0;
}