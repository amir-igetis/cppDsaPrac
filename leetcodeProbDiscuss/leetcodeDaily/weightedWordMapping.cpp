#include <bits/stdc++.h>
using namespace std;

string mapWordWeights(vector<string> &words, vector<int> &weights)
{
    string ans;
    ans.reserve(words.size());
    for (auto &word : words)
    {
        int s = 0;
        for (auto &c : word)
            s += weights[c - 'a'];

        ans += 'z' - (s % 26);
    }
    return ans;
}

int main()
{
    vector<string> words = {"abcd", "def", "xyz"};
    vector<int> weights = {5, 3, 12, 14, 1, 2, 3, 2, 10, 6, 6, 9, 7, 8, 7, 10, 8, 9, 6, 9, 9, 8, 3, 7, 7, 2};

    cout << mapWordWeights(words, weights) << endl;

    return 0;
}