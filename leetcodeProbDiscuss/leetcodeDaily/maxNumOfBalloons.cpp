#include <bits/stdc++.h>
using namespace std;

int maxNumberOfBalloons(string text)
{
    vector<int> freq(26);

    for (char ch : text)
    {
        freq[ch - 'a']++;
    }

    return min(
        min(freq['b' - 'a'], freq['a' - 'a']),
        min(
            min(freq['l' - 'a'] / 2, freq['o' - 'a'] / 2),
            freq['n' - 'a']));
}

int main()
{
    string text = "leetcode";
    cout << maxNumberOfBalloons(text) << endl;

    return 0;
}