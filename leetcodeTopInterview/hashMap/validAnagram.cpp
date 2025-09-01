#include <bits/stdc++.h>
using namespace std;

bool isAnagram(string s, string t)
{
    if (s.size() != t.size())
        return false;

    unordered_map<char, int> countMp;
    for (char ch : s)
    {
        countMp[ch]++;
    }

    for (char ch : t)
    {

        // this also works, know the difference between count and find == end
        // if (!countMp.count(ch) || countMp[ch] == 0)
        // Check if character not found or count is zero
        if (countMp.find(ch) == countMp.end() || countMp[ch] == 0)
            return false;

        countMp[ch]--;
    }
    return true;
}

int main()
{

    string s = "anagram", t = "nagram";

    cout << isAnagram(s, t) << endl;

    return 0;
}