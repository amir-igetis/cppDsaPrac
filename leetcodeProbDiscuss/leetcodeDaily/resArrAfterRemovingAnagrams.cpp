#include <bits/stdc++.h>
using namespace std;

vector<string> removeAnagrams(vector<string> &words)
{
    vector<string> res;
    string prevSorted = "";
    for (auto &i : words)
    {
        string chars = i;
        sort(chars.begin(), chars.end());
        string sortedWord = chars;
        if (sortedWord != prevSorted)
        {
            res.push_back(i);
            prevSorted = sortedWord;
        }
    }
    return res;
}

int main()
{

    vector<string> words = {"abba", "baba", "bbaa", "cd", "cd"};
    vector<string> ans = removeAnagrams(words);
    for (auto &i : ans)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}