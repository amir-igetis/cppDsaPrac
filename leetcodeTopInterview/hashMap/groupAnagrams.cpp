#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    unordered_map<string, vector<string>> mp;

    for (string word : strs)
    {
        string key = word;
        sort(key.begin(), key.end()); // Sort letters to form key
        mp[key].push_back(word);
    }

    // understand this part
    vector<vector<string>> result;
    for (auto &entry : mp)
    {
        result.push_back(entry.second);
    }
    return result;
}

int main()
{

    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> grouped = groupAnagrams(strs);

    for (auto &group : grouped)
    {
        for (auto &word : group)
        {
            cout << word << " ";
        }
        cout << endl;
    }

    return 0;
}