#include <bits/stdc++.h>
using namespace std;

// weighted word mapping
string mapWordWeights(vector<string> &words, vector<int> &weights)
{

    string res;
    for (int i = 0; i < words.size(); i++)
    {
        int wt = 0;
        for (int j = 0; j < words[i].size(); j++)
        {
            wt += weights[words[i][j] - 'a'];
        }
        int mod = wt % 26;
        char rev = 'z' - mod;
        res.push_back(rev);
    }
    return res;
}

int main()
{

    vector<string> words = {"abcd", "def", "xyz"};
    vector<int> weights = {5, 3, 12, 14, 1, 2, 3, 2, 10, 6, 6, 9, 7, 8, 7, 10, 8, 9, 6, 9, 9, 8, 3, 7, 7, 2};
    cout << mapWordWeights(words, weights) << endl;

    return 0;
}