#include <bits/stdc++.h>
using namespace std;

struct TrieNode
{
    unordered_map<char, TrieNode *> children;
    int latest_index;
    TrieNode() : latest_index(-1) {}
};

vector<int> autoComplete(vector<string> commands)
{
    vector<int> result;
    TrieNode *root = new TrieNode();

    for (int i = 0; i < commands.size(); ++i)
    {
        const string &cmd = commands[i];
        if (i == 0)
        {
            result.push_back(0);
        }
        else
        {
            TrieNode *current = root;
            int best_index = -1;
            for (char c : cmd)
            {
                if (current->children.find(c) != current->children.end())
                {
                    current = current->children[c];
                    best_index = current->latest_index;
                }
                else
                {
                    break;
                }
            }
            if (best_index == -1)
            {
                best_index = i - 1;
            }
            result.push_back(best_index + 1);
        }

        TrieNode *current = root;
        for (char c : cmd)
        {
            if (current->children.find(c) == current->children.end())
            {
                current->children[c] = new TrieNode();
            }
            current = current->children[c];
            if (current->latest_index < i)
            {
                current->latest_index = i;
            }
        }
    }

    return result;
}

int main()
{

    // vector<string> commands = {"000", "1110", "01", "001", "110", "11"};
    vector<string> commands = {"1", "10", "11010"};

    vector<int> ans = autoComplete(commands);

    for (int i : ans)
    {
        cout << i << ", ";
    }
    cout << endl;

    vector<vector<int>> ansI;

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// vector<int> solution(int length, vector<vector<int>> queries)
// {
//     vector<int> result;
//     vector<int> line(length, -1);
//     int count = 0;

//     for (auto &q : queries)
//     {
//         int idx = q[0];
//         int color = q[1];

//         if (line[idx] == color)
//         {
//             result.push_back(count);
//             continue;
//         }

//         if (idx > 0 && line[idx - 1] == line[idx] && line[idx] != -1)
//             count--;

//         if (idx < length - 1 && line[idx + 1] == line[idx] && line[idx] != -1)
//             count--;

//         line[idx] = color;

//         if (idx > 0 && line[idx - 1] == color)
//             count++;

//         if (idx < length - 1 && line[idx + 1] == color)
//             count++;

//         result.push_back(count);
//     }

//     return result;
// }

// int main()
// {
//     int length = 7;
//     vector<vector<int>> queries = {
//         {1, 2}, {0, 2}, {3, 5}, {3, 2}, {2, 2}, {6, 1}, {1, 3}};

//     vector<int> res = solution(length, queries);

//     for (int x : res)
//         cout << x << " ";
//     return 0;
// }