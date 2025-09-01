#include <bits/stdc++.h>
using namespace std;

string removeVowels(const string &word)
{
    string result;
    for (char ch : word)
    {
        if (ch != 'a' && ch != 'e' && ch != 'i' && ch != 'o' && ch != 'u')
        {
            result += ch;
        }
    }
    return result;
}
string shortenSentence(string sentence)
{
    unordered_map<string, int> wordCount;
    stringstream ss(sentence);
    string word;
    vector<string> shortenedWords;
    while (ss >> word)
    {
        string shortened = removeVowels(word);
        if (wordCount[shortened] > 0)
        {
            shortened += to_string(wordCount[shortened]);
        }

        wordCount[shortened]++;
        shortenedWords.push_back(shortened);
    }

    string result;
    for (size_t i = 0; i < shortenedWords.size(); ++i)
    {
        if (i > 0)
        {
            result += " ";
        }
        result += shortenedWords[i];
    }

    return result;
}

int main()
{
    string sentence = "kra kru pra pur pur par what what";
    string result = shortenSentence(sentence);
    cout << result << endl;
}
