#include <bits/stdc++.h>
using namespace std;

int canBeTypedWords(string text, string brokenLetters)
{
    unordered_set<char> broken(brokenLetters.begin(), brokenLetters.end());
    stringstream ss(text);
    string word;
    int count = 0;
    while (ss >> word)
    {
        bool canType = true;
        for (char ch : word)
        {
            if (broken.count(ch))
            {
                canType = false;
                break;
            }
        }
        if (canType)
            count++;
    }
    return count;
}

int main()
{
    string text = "hello world", brokenLetters = "ad";
    cout << canBeTypedWords(text, brokenLetters) << endl;

    return 0;
}