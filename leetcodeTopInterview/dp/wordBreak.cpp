#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *links[26];
    bool flag = false;

    bool containsKey(char ch)
    {
        return links[ch - 'a'] != NULL;
    }
    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }
    Node *get(char ch)
    {
        return links[ch - 'a'];
    }
    void setEnd()
    {
        flag = true;
    }
    bool isEnd()
    {
        return flag;
    }
};

class Trie
{
public:
    Node *root;
    Trie() { root = new Node(); }

    void insert(string word)
    {
        Node *node = root;
        for (char ch : word)
        {
            if (!node->containsKey(ch))
            {
                node->put(ch, new Node());
            }
            node = node->get(ch);
        }
        node->setEnd();
    }
};

// DFS that walks over Trie directly
bool dfs(Node *root, string &s, int index)
{
    if (index == s.size())
        return true;

    Node *node = root;
    for (int i = index; i < s.size(); i++)
    {
        if (!node->containsKey(s[i]))
            return false;
        node = node->get(s[i]);
        if (node->isEnd() && dfs(root, s, i + 1))
        {
            return true;
        }
    }
    return false;
}

bool wordBreakTrieDFS(string s, vector<string> &wordDict)
{
    Trie trie;
    for (string &word : wordDict)
        trie.insert(word);
    return dfs(trie.root, s, 0);
}

bool wordBreak(string s, vector<string> &wordDict)
{
    unordered_set<string> dict(wordDict.begin(), wordDict.end());
    vector<bool> dp(s.length() + 1, false);
    dp[0] = true;

    for (int i = 1; i <= s.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (dp[j] && dict.count(s.substr(j, i - j)))
            {
                dp[i] = true;
                break;
            }
        }
    }
    return dp[s.size()];
}

bool wordBreakBFS(string s, vector<string> &wordDict)
{
    unordered_set<string> dict(wordDict.begin(), wordDict.end());
    queue<int> q;
    vector<bool> visited(s.size(), false);

    q.push(0);
    while (!q.empty())
    {
        int start = q.front();
        q.pop();
        if (visited[start])
            continue;

        for (int end = start + 1; end <= s.size(); end++)
        {
            if (dict.count(s.substr(start, end - start)))
            {
                if (end == s.size())
                    return true;
                q.push(end);
            }
        }
        visited[start] = true;
    }
    return false;
}

unordered_map<int, bool> memo;
unordered_set<string> dictDFS;

bool dfs(string &s, int start)
{
    if (start == s.size())
        return true;
    if (memo.count(start))
        return memo[start];

    for (int end = start + 1; end <= s.size(); end++)
    {
        if (dictDFS.count(s.substr(start, end - start)) && dfs(s, end))
        {
            return memo[start] = true;
        }
    }
    return memo[start] = false;
}

bool wordBreakDFS(string s, vector<string> &wordDict)
{
    dictDFS = unordered_set<string>(wordDict.begin(), wordDict.end());
    memo.clear();
    return dfs(s, 0);
}

int main()
{

    string s = "applepenapple";
    vector<string> wordDict = {"apple", "pen"};

    cout << "DP:   " << (wordBreak(s, wordDict) ? "true" : "false") << endl;
    cout << "DFS:  " << (wordBreakDFS(s, wordDict) ? "true" : "false") << endl;
    cout << "BFS:  " << (wordBreakBFS(s, wordDict) ? "true" : "false") << endl;
    cout << "Trie:  " << (wordBreakTrieDFS(s, wordDict) ? "true" : "false") << endl;

    return 0;
}