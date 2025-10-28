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

vector<vector<string>> groupAnagramsI(vector<string> &strs)
{
    unordered_map<string, vector<string>> mp;
    for (auto &s : strs)
    {
        vector<int> count(26);
        for (auto &ch : s)
            count[ch - 'a']++;

        stringstream keyBuilder;
        for (auto &num : count)
            keyBuilder << num << '#';

        string key = keyBuilder.str();
        mp[key].push_back(s);
    }

    vector<vector<string>> res;

    for (auto &entry : mp)
        res.push_back(entry.second);

    return res;
}

vector<vector<string>> groupAnagramsII(vector<string> &strs)
{
    vector<vector<string>> res;
    unordered_map<string, vector<string>> mp;

    for (auto &str : strs)
    {
        // Count frequency of each character
        vector<char> arr(26, 0);
        for (char c : str)
        {
            arr[c - 'a']++;
        }

        // Convert frequency array to string key
        string key(arr.begin(), arr.end());

        // Add word to map
        mp[key].push_back(str);
    }

    // Collect all grouped anagrams
    for (auto &entry : mp)
    {
        res.push_back(entry.second);
    }

    return res;
}

int main()
{

    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> grouped = groupAnagramsI(strs);

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