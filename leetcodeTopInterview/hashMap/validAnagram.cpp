#include <bits/stdc++.h>
using namespace std;

bool isAnagramI(string s, string t)
{
    if (s.size() != t.size())
        return false;

    vector<int> count(26);
    for (auto &i : s)
        count[i - 'a']++;

    for (auto &i : t)
    {
        count[i - 'a']--;
        if (count[i - 'a'] < 0)
            return false;
    }

    return true;
}

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

    cout << (isAnagramI(s, t) ? "True" : "False") << endl;

    return 0;
}