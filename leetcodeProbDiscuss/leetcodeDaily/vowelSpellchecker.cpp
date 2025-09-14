#include <bits/stdc++.h>
using namespace std;

string toLower(string s)
{
    for (char &c : s)
        c = tolower(c);
    return s;
}

// helper to mask vowels with '*'
string devowel(string s)
{
    for (char &c : s)
    {
        char low = tolower(c);
        if (low == 'a' || low == 'e' || low == 'i' || low == 'o' || low == 'u')
            c = '*';
        else
            c = low; // normalize consonants to lowercase
    }
    return s;
}

vector<string> spellchecker(vector<string> &wordlist, vector<string> &queries)
{
    unordered_set<string> exactSet;                 // for exact match
    unordered_map<string, string> caseInsensitive;  // lowercase -> original
    unordered_map<string, string> vowelInsensitive; // devowel -> original

    // preprocess wordlist
    for (string word : wordlist)
    {
        exactSet.insert(word);

        string lower = toLower(word);
        if (!caseInsensitive.count(lower))
        {
            caseInsensitive[lower] = word;
        }

        string vmask = devowel(word);
        if (!vowelInsensitive.count(vmask))
        {
            vowelInsensitive[vmask] = word;
        }
    }

    vector<string> result;
    for (string query : queries)
    {
        if (exactSet.count(query))
        {
            result.push_back(query); // exact match
        }
        else
        {
            string lower = toLower(query);
            if (caseInsensitive.count(lower))
            {
                result.push_back(caseInsensitive[lower]); // case-insensitive match
            }
            else
            {
                string vmask = devowel(query);
                if (vowelInsensitive.count(vmask))
                {
                    result.push_back(vowelInsensitive[vmask]); // vowel error match
                }
                else
                {
                    result.push_back(""); // no match
                }
            }
        }
    }

    return result;
}

int main()
{

    vector<string> wordlist = {"KiTe", "kite", "hare", "Hare"};
    vector<string> queries = {"kite", "Kite", "KiTe", "Hare", "HARE", "Hear", "hear", "keti", "keet", "keto"};

    vector<string> res = spellchecker(wordlist, queries);
    for (string i : res)
        cout << i << " ";
    cout << endl;

    return 0;
}