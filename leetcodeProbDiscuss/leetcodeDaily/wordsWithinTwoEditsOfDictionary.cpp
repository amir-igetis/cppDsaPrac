#include <bits/stdc++.h>
using namespace std;

// brute force

vector<string> twoEditWordsI(vector<string> &queries, vector<string> &dictionary)
{
    vector<string> ans;
    for (string query : queries)
    {
        for (string s : dictionary)
        {
            int dis = 0;
            for (int i = 0; i < query.size(); i++)
            {
                if (query[i] != s[i])
                {
                    ++dis;
                }
            }
            if (dis <= 2)
            {
                ans.push_back(query);
                break;
            }
        }
    }
    return ans;
}

// Trie
struct TrieNode
{
    TrieNode *child[26];
    bool isEnd;
    TrieNode()
    {
        memset(child, 0, sizeof(child));
        isEnd = false;
    }
};

TrieNode *root = new TrieNode();

void insert(string &word)
{
    TrieNode *node = root;
    for (char c : word)
    {
        int idx = c - 'a';
        if (!node->child[idx])
            node->child[idx] = new TrieNode();
        node = node->child[idx];
    }
    node->isEnd = true;
}

bool dfs(string &word, int i, TrieNode *node, int cnt)
{
    if (cnt > 2)
        return false;
    if (!node)
        return false;

    if (i == word.size())
    {
        return node->isEnd;
    }

    int idx = word[i] - 'a';

    // no changes made
    if (node->child[idx])
    {
        if (dfs(word, i + 1, node->child[idx], cnt))
            return true;
    }

    // made changes
    if (cnt < 2)
    {
        for (int c = 0; c < 26; c++)
        {
            if (c == idx)
                continue;
            if (node->child[c])
            {
                if (dfs(word, i + 1, node->child[c], cnt + 1))
                    return true;
            }
        }
    }

    return false;
}

vector<string> twoEditWords(vector<string> &queries, vector<string> &dictionary)
{
    for (auto &w : dictionary)
        insert(w);

    vector<string> res;
    for (auto &q : queries)
    {
        if (dfs(q, 0, root, 0))
        {
            res.push_back(q);
        }
    }
    return res;
}

int main()
{

    vector<string> queries = {"word", "note", "ants", "wood"}, dictionary = {"wood", "joke", "moat"};
    vector<string> ans = twoEditWordsI(queries, dictionary);

    for (auto &i : ans)
        cout << i << " ";

    cout << endl;

    return 0;
}