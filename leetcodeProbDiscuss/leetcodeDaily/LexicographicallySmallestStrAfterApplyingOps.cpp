#include <bits/stdc++.h>
using namespace std;

string findLexSmallestString(string s, int a, int b)
{
    unordered_set<string> seen;
    queue<string> q;
    string ans = s;
    q.push(s);
    seen.insert(s);

    while (!q.empty())
    {
        string curr = q.front();
        q.pop();

        ans = min(ans, curr);

        string addOp = curr;
        for (int i = 1; i < addOp.size(); i += 2)
        {
            addOp[i] = (addOp[i] - '0' + a) % 10 + '0';
        }

        if (!seen.count(addOp))
        {
            seen.insert(addOp);
            q.push(addOp);
        }

        string rotOp = curr.substr(curr.size() - b) + curr.substr(0, curr.size() - b);
        if (!seen.count(rotOp))
        {
            seen.insert(rotOp);
            q.push(rotOp);
        }
    }
    return ans;
}

int main()
{

    string s = "5525";
    int a = 9, b = 2;
    cout << findLexSmallestString(s, a, b) << endl;
    return 0;
}