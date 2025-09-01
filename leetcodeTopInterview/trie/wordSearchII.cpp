
#include <bits/stdc++.h>
using namespace std;

struct TrieNode
{
    TrieNode *links[26];
    bool isEnd = false;
    string word = ""; // store word at the end node

    TrieNode()
    {
        for (int i = 0; i < 26; i++)
            links[i] = NULL;
    }

    bool containsKey(char ch)
    {
        return links[ch - 'a'] != NULL;
    }

    TrieNode *get(char ch)
    {
        return links[ch - 'a'];
    }

    void put(char ch, TrieNode *node)
    {
        links[ch - 'a'] = node;
    }
};

// Build Trie
class Trie
{
public:
    TrieNode *root;
    Trie()
    {
        root = new TrieNode();
    }

    void insert(string &word)
    {
        TrieNode *node = root;
        for (char c : word)
        {
            if (!node->containsKey(c))
            {
                node->put(c, new TrieNode());
            }
            node = node->get(c);
        }
        node->isEnd = true;
        node->word = word; // store complete word
    }
};

class Solution
{
    int m, n;
    vector<string> res;
    vector<vector<char>> board;
    vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    void dfs(int r, int c, TrieNode *node)
    {
        char ch = board[r][c];

        if (!node->containsKey(ch))
            return;

        node = node->get(ch);
        if (node->isEnd)
        {
            res.push_back(node->word);
            node->isEnd = false;
        }

        board[r][c] = '#';
        for (auto &d : dirs)
        {
            int nr = r + d[0], nc = c + d[1];
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && board[nr][nc] != '#')
                dfs(nr, nc, node);
        }
        board[r][c] = ch;
    }

    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        this->board = board;
        m = board.size(), n = board[0].size();

        Trie trie;

        for (auto &w : words)
            trie.insert(w);

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
                dfs(i, j, trie.root);
        }
        return res;
    }
};

int main()
{

    return 0;
}