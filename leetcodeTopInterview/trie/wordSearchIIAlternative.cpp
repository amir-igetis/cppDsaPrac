#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node *link[26];
    bool flag = false;
    string word = "";

    bool containsKey(char ch)
    {
        return link[ch - 'a'];
    }
    void put(char ch, Node *node)
    {
        link[ch - 'a'] = node;
    }
    Node *get(char ch)
    {
        return link[ch - 'a'];
    }
    bool isEnd()
    {
        return flag;
    }
    void setEnd()
    {
        flag = true;
    }
    void setWord(string str)
    {
        word = str;
    }
};

class Solution
{
public:
    Node *root = new Node();
    int m, n;
    vector<string> result;

    void insert(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
        node->setWord(word);
    }

    void dfs(vector<vector<char>> &board, int i, int j, Node *node)
    {
        char ch = board[i][j];
        if (ch == '!' || !node->containsKey(ch))
            return;
        node = node->get(ch);

        if (!node->word.empty())
        {
            result.push_back(node->word);
            node->word = ""; // to avoid duplicates
        }

        board[i][j] = '!'; // mark as visited

        if (i > 0)
            dfs(board, i - 1, j, node);
        if (j > 0)
            dfs(board, i, j - 1, node);
        if (i < m - 1)
            dfs(board, i + 1, j, node);
        if (j < n - 1)
            dfs(board, i, j + 1, node);

        board[i][j] = ch; // backtrack
    }
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        m = board.size();
        n = board[0].size();
        for (string &word : words)
        {
            insert(word);
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                dfs(board, i, j, root);
            }
        }
        return result;
    }
};

int main()
{

    vector<vector<char>> board = {
        {'o', 'a', 'a', 'n'},
        {'e', 't', 'a', 'e'},
        {'i', 'h', 'k', 'r'},
        {'i', 'f', 'l', 'v'}};

    vector<string> words = {"oath", "pea", "eat", "rain"};

    Solution sol;
    vector<string> ans = sol.findWords(board, words);

    for (auto &i : ans)
        cout << i << " ";

    cout << endl;

    return 0;
}