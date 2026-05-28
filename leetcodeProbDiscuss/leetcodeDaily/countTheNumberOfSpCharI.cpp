#include <bits/stdc++.h>
using namespace std;

int numberOfSpecialChars(string word)
{
    unordered_set<char> s(word.begin(), word.end());
    int ans = 0;
    for (char c = 'a'; c <= 'z'; c++)
    {
        if (s.count(c) && s.count(c - 'a' + 'A'))
        {
            ans++;
        }
    }
    return ans;
}

int main()
{
    string word = "aaAbcBC";
    cout << numberOfSpecialChars(word) << endl;

    return 0;
}