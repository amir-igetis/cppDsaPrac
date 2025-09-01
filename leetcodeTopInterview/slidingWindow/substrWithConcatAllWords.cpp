#include <bits/stdc++.h>
using namespace std;

vector<int> findSubstring(string s, vector<string> &words)
{

    vector<int> res;
    if (words.empty() || s.empty())
        return res;

    int wordLen = words[0].size(), wordCount = words.size(), totalLen = wordLen * wordCount;

    unordered_map<string, int> freq;
    for (const string &word : words)
        freq[word]++;

    for (int i = 0; i < wordLen; i++)
    {
        int left = i, right = i;
        unordered_map<string, int> seen;

        while (right + wordLen <= s.size())
        {
            string word = s.substr(right, wordLen);
            right += wordLen;

            if (freq.find(word) != freq.end())
            {
                seen[word]++;

                while (seen[word] > freq[word])
                {
                    string leftWord = s.substr(left, wordLen);
                    seen[leftWord]--;
                    left += wordLen;
                }
                if (right - left == totalLen)
                    res.push_back(left);
            }
            else
            {
                seen.clear();
                left = right;
            }
        }
    }
    return res;
}

int main()
{

    string s = "barfoothefoobarman";
    vector<string> words = {"foo", "bar"};

    vector<int> ans = findSubstring(s, words);
    for (int i : ans)
        cout << i << " ";
    cout << endl;

    return 0;
}