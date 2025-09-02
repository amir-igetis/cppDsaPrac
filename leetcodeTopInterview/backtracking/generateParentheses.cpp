#include <bits/stdc++.h>
using namespace std;

void backtrack(vector<string> &res, string curr, int start, int end, int max)
{
    if (curr.size() == max * 2)
    {
        res.push_back(curr);
        return;
    }

    if (start < max)
    {
        backtrack(res, curr + "(", start + 1, end, max);
    }
    if (end < start)
    {
        backtrack(res, curr + ")", start, end + 1, max);
    }
}

vector<string> generateParenthesis(int n)
{
    vector<string> res;
    backtrack(res, "", 0, 0, n);
    return res;
}

int main()
{

    int n = 3;
    vector<string> ans = generateParenthesis(n);

    for (string &i : ans)
        cout << i << " ";
    cout << endl;

    return 0;
}