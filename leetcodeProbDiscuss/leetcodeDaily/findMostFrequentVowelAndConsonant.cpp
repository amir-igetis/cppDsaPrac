#include <bits/stdc++.h>
using namespace std;

int mostFrequentVowelConsonant(string s)
{
    vector<int> freq(26, 0);

    for (char ch : s)
    {
        freq[ch - 'a']++;
    }

    unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
    int maxVowel = 0, maxConsonant = 0;

    for (int i = 0; i < 26; i++)
    {
        char ch = 'a' + i;
        if (freq[i] > 0)
        {
            if (vowels.count(ch))
            {
                maxVowel = max(maxVowel, freq[i]);
            }
            else
            {
                maxConsonant = max(maxConsonant, freq[i]);
            }
        }
    }

    return maxVowel + maxConsonant;
}

int mostFrequentVowelConsonantHashI(string s)
{
    unordered_map<char, int> freqMap;
    for (char ch : s)
    {
        freqMap[ch]++;
    }

    unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
    int maxVowel = 0, maxConsonant = 0;

    for (auto &p : freqMap)
    {
        char ch = p.first;
        int count = p.second;
        if (vowels.count(ch))
        {
            maxVowel = max(maxVowel, count);
        }
        else
        {
            maxConsonant = max(maxConsonant, count);
        }
    }

    return maxVowel + maxConsonant;
}

int main()
{

    string s = "successes";
    cout << mostFrequentVowelConsonant(s) << endl;

    return 0;
}