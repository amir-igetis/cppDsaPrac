#include <bits/stdc++.h>
using namespace std;

bool canConstruct(string ransomNote, string magazine)
{
    unordered_map<char, int> letterCount;

    // Count all letters in magazine
    for (char ch : magazine)
    {
        letterCount[ch]++;
    }

    // Check ransom note
    for (char ch : ransomNote)
    {
        // If character not found or count is zero
        if (letterCount.find(ch) == letterCount.end() || letterCount[ch] == 0)
        {
            return false;
        }
        letterCount[ch]--; // Use one occurrence
    }

    return true;
}

bool canConstructI(string ransomNote, string magazine)
{

    vector<int> count(128);
    for (char ch : magazine)
        count[ch - 'a']++;

    for (char ch : ransomNote)
    {
        if (count[ch - 'a'] == 0)
            return false;

        count[ch - 'a']--;
    }
    return true;
}

int main()
{

    string ransomNote = "a", magazine = "b";

    cout << (canConstruct(ransomNote, magazine) ? "True" : "False") << endl;

    return 0;
}