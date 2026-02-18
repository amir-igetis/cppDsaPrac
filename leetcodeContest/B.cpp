#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *links[26];
    int count;
    Node()
    {
        count = 0;
        for (int i = 0; i < 26; i++)
            links[i] = nullptr;
    }

    bool containsKey(char ch)
    {
        return links[ch - 'a'] != nullptr;
    }
    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }
    Node *get(char ch)
    {
        return links[ch - 'a'];
    }
};

class Trie
{
public:
    Node *root;
    Trie()
    {
        root = new Node();
    }

    void insertPrefix(string &word, int k)
    {
        Node *node = root;
        for (int i = 0; i < k; i++)
        {
            if (!node->containsKey(word[i]))
                node->put(word[i], new Node());

            node = node->get(word[i]);
        }
        node->count++;
    }

    int countGroups(Node *node, int deep, int k)
    {
        if (!node)
            return 0;
        int group = 0;
        if (deep == k)
        {
            if (node->count >= 2)
                return 1;
            return 0;
        }

        for (int i = 0; i < 26; i++)
            group += countGroups(node->links[i], deep + 1, k);

        return group;
    }
};

int prefixConnected(vector<string> &words, int k)
{
    Trie trie;
    for (auto &i : words)
    {
        if (i.size() >= k)
            trie.insertPrefix(i, k);
    }
    return trie.countGroups(trie.root, 0, k);
}

int main()
{
    // vector<string> words = {"car", "cat", "cartoon"};
    // int k = 3;

    vector<string> words = {"bat", "dog", "dog", "doggy", "bat"};
    int k = 3;

    cout << prefixConnected(words, k) << endl;

    return 0;
}