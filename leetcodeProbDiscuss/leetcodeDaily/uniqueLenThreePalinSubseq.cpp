#include <bits/stdc++.h>
using namespace std;

int countPalindromicSubsequence(string s)
{
    int n = s.size();
    vector<int> first(26, -1), last(26, -1);

    for (int i = 0; i < n; i++)
    {
        int c = s[i] - 'a';
        if (first[c] == -1)
            first[c] = i;
        last[c] = i;
    }

    int res = 0;

    for (int c = 0; c < 26; c++)
    {
        if (first[c] != -1 && last[c] != -1 && first[c] < last[c])
        {
            vector<bool> seen(26, false);

            for (int i = first[c] + 1; i < last[c]; i++)
                seen[s[i] - 'a'] = true;

            for (bool b : seen)
                if (b)
                    res++;
        }
    }
    return res;
}

int main()
{
    string s = "bbcbaba";
    cout << countPalindromicSubsequence(s) << endl;

    return 0;
}