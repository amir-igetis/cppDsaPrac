#include <bits/stdc++.h>
using namespace std;

// map and dfs
class Solution
{
public:
    unordered_map<string, vector<char>> mp;
    unordered_set<string> seen;

    bool pyramidTransition(string bottom, vector<string> &allowed)
    {
        mp.clear();
        seen.clear();

        for (string &s : allowed)
        {
            mp[s.substr(0, 2)].push_back(s[2]);
        }
        return dfs(bottom, "");
    }

private:
    bool dfs(string curr, string next)
    {
        if (curr.size() == 1)
            return true;

        if (next.size() + 1 == curr.size())
        {
            if (!seen.insert(next).second)
                return false;
            return dfs(next, "");
        }

        int i = next.size();
        string key = curr.substr(i, 2);

        if (!mp.count(key))
            return false;

        for (char c : mp[key])
        {
            if (dfs(curr, next + c))
                return true;
        }
        return false;
    }
};

// bfs and bitmask

class SolutionI
{
public:
    int T[7][7] = {};
    unordered_set<string> seen;

    bool pyramidTransition(string bottom, vector<string> &allowed)
    {
        memset(T, 0, sizeof(T));
        seen.clear();

        for (string &s : allowed)
        {
            T[s[0] - 'A'][s[1] - 'A'] |= 1 << (s[2] - 'A');
        }
        return dfs(bottom, "");
    }

private:
    bool dfs(string curr, string next)
    {
        if (curr.size() == 1)
            return true;

        if (next.size() + 1 == curr.size())
        {
            if (seen.count(next))
                return false;
            seen.insert(next);
            return dfs(next, "");
        }

        int i = next.size();
        int mask = T[curr[i] - 'A'][curr[i + 1] - 'A'];

        for (int b = 0; b < 7; b++)
        {
            if (mask & (1 << b))
            {
                if (dfs(curr, next + char('A' + b)))
                    return true;
            }
        }
        return false;
    }
};

int main()
{

    string bottom = "BCD";
    vector<string> allowed = {"BCC", "CDE", "CEA", "FFF"};
    Solution sol;
    SolutionI solI;
    // SolutionI sl = new Solution();
    bool ans = sol.pyramidTransition(bottom, allowed);
    bool res = solI.pyramidTransition(bottom, allowed);
    cout << (ans ? "True" : "False") << (res ? "TRUE" : "FALSE") << endl;

    return 0;
}
