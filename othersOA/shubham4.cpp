#include <bits/stdc++.h>
using namespace std;

vector<string> solution(vector<string> wordsList)
{
    vector<string> result;

    for (string word : wordsList)
    {
        if (word.length() % 2 == 0)
            reverse(word.begin(), word.end());
        else
            transform(word.begin(), word.end(), word.begin(), ::toupper);
        result.push_back(word);
    }

    return result;
}

vector<string> solutionI(vector<string> wordsList)
{
    vector<string> result;

    for (string word : wordsList)
    {
        if (word.length() % 2 == 0)
            reverse(word.begin(), word.end());
        else
            for (int i = 0; i < word.length(); i++)
                word[i] = toupper(word[i]);

        result.push_back(word);
    }
    return result;
}

int main()
{
    // Test case 1
    vector<string> wordsList = {"HeLLo", "Data", "science"};
    vector<string> result = solution(wordsList);

    for (string word : result)
    {
        cout << word << endl;
    }

    // Test case 2 (empty list)
    wordsList = {};
    result = solution(wordsList);

    for (string word : result)
    {
        cout << word << endl;
    }

    return 0;
}
