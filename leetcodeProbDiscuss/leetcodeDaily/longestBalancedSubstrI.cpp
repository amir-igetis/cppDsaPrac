#include <bits/stdc++.h>
using namespace std;

int longestBalanced(string s)
{
    int n = s.size();
    int res = 0;
    vector<int> count(26);
    for (int i = 0; i < n; i++)
    {
        fill(count.begin(), count.end(), 0);
        for (int j = i; j < n; j++)
        {
            bool flag = true;
            int c = s[j] - 'a';
            count[c]++;
            for (auto &x : count)
            {
                if (x > 0 && x != count[c])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
                res = max(res, j - i + 1);
        }
    }
    return res;
}

int main()
{

    string s = "abbac";
    cout << longestBalanced(s) << endl;

    return 0;
}