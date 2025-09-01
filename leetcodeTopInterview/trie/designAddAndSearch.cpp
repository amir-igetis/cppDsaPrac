#include <bits/stdc++.h>
using namespace std;

struct Node
{

public:
    Node *links[26];
    bool flag = false;

    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }

    bool containsKey(char ch)
    {
        return links[ch - 'a'] != NULL;
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

class WordDictionary
{

private:
    Node *root;

public:
    WordDictionary()
    {
        root = new Node();
    }

    void addWord(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!node->containsKey(word[i]))
                node->put(word[i], new Node());

            node = node->get(word[i]);
        }

        node->setEnd();
    }

    bool searchUntil(string &word, int idx, Node *node)
    {
        if (idx == word.length())
            return node->isEnd();

        char ch = word[idx];

        if (ch == '.')
        {
            for (int i = 0; i < 26; i++)
            {
                if (node->links[i] && searchUntil(word, idx + 1, node->links[i]))
                {
                    return true;
                }
            }
            return false;
        }
        else
        {
            if (!node->containsKey(ch))
                return false;

            return searchUntil(word, idx + 1, node->get(ch));
        }
    }

    bool search(string word)
    {
        return searchUntil(word, 0, root);
    }
};

int main()
{

    return 0;
}

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */