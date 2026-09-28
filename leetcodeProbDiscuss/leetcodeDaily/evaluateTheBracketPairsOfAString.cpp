#include<bits/stdc++.h>
using namespace std;

// Hash Table

/// Let n be the length of s, and let m be the total length of all strings in knowledge.
///
/// Time complexity: O(n+m).
///
/// Building the hash table takes O(m) time. Traversing s, extracting keys, looking them up in the hash table, and appending characters and values to the result string takes O(n+m) time. Thus, the total time complexity is O(n+m).
///
/// Space complexity: O(n+m).
///
/// The hash table stores all key-value pairs from knowledge, which requires O(m) space. The output string (and key buffer) requires O(n+m) space.

string evaluate(string s, vector<vector<string>> &knowledge)
{
    unordered_map<string, string> dict;
    for (auto &kd : knowledge)
    {
        dict[kd[0]] = kd[1];
    }
    bool addKey = false;
    string key, res;
    for (char c : s)
    {
        if (c == '(')
        {
            addKey = true;
        }
        else if (c == ')')
        {
            if (dict.count(key) > 0)
            {
                res += dict[key];
            }
            else
            {
                res.push_back('?');
            }
            addKey = false;
            key.clear();
        }
        else if (addKey)
        {
            key.push_back(c);
        }
        else
        {
            res.push_back(c);
        }
    }
    return res;
}

int main()
{
    string s = "(name)is(age)yearsold";
    vector<vector<string>> knowledge = {
        {"name", "bob"},
        {"age", "two"}};
    cout << evaluate(s, knowledge) << endl;

    return 0;
}