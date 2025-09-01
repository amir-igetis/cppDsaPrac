#include <bits/stdc++.h>
using namespace std;

int ladderLength(string beginWord, string endWord, vector<string> &wordList)
{
    unordered_set<string> wordSt(wordList.begin(), wordList.end());
    if (wordSt.find(endWord) == wordSt.end())
        return 0;

    queue<string> q;
    q.push(beginWord);
    int steps = 1;

    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            string word = q.front();
            q.pop();

            if (word == endWord)
                return steps;

            string wordChars = word;
            for (int j = 0; j < wordChars.size(); j++)
            {
                char original = wordChars[j];
                for (char c = 'a'; c <= 'z'; c++)
                {
                    if (c == original)
                        continue;
                    wordChars[j] = c;
                    if (wordSt.find(wordChars) != wordSt.end())
                    {
                        q.push(wordChars);
                        wordSt.erase(wordChars); // mark visited
                    }
                }
                wordChars[j] = original; // restore
            }
        }
        steps++;
    }
    return 0;
}

// Bidirectional BFS
int ladderLengthI(string beginWord, string endWord, vector<string> &wordList)
{
    unordered_set<string> dict(wordList.begin(), wordList.end());
    if (dict.find(endWord) == dict.end())
        return 0; // endWord must be in dict

    unordered_set<string> beginSet, endSet, visited;
    beginSet.insert(beginWord);
    endSet.insert(endWord);

    int steps = 1;

    while (!beginSet.empty() && !endSet.empty())
    {
        // Always expand the smaller frontier
        if (beginSet.size() > endSet.size())
        {
            swap(beginSet, endSet);
        }

        unordered_set<string> nextSet;
        for (string word : beginSet)
        {
            string temp = word;
            for (int i = 0; i < temp.size(); i++)
            {
                char original = temp[i];
                for (char c = 'a'; c <= 'z'; c++)
                {
                    if (c == original)
                        continue;
                    temp[i] = c;
                    if (endSet.find(temp) != endSet.end())
                    {
                        return steps + 1; // Found meeting point
                    }

                    if (dict.find(temp) != dict.end() && visited.find(temp) == visited.end())
                    {
                        nextSet.insert(temp);
                        visited.insert(temp);
                    }
                }
                temp[i] = original;
            }
        }

        beginSet = nextSet;
        steps++;
    }

    return 0;
}

int main()
{

    string beginWord = "hit", endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};

    cout << ladderLength(beginWord, endWord, wordList) << endl;

    return 0;
}