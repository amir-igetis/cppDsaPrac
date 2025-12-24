

#include <bits/stdc++.h>
using namespace std;

bool canExtend(vector<string> &strs, int j, int i)
{
    for (auto &s : strs)
    {
        if (s[j] > s[i])
            return false;
    }

    return true;
}

int minDeletionSize(vector<string> &strs)
{
    int n = strs.size();
    int w = strs[0].length();
    vector<int> dp(w, 1);
    int maxKept = 1;
    // Arrays.fill(dp, 1);
    for (int i = 0; i < w; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (canExtend(strs, j, i))
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        maxKept = max(maxKept, dp[i]);
    }
    return w - maxKept;
}

int main()
{

    vector<string> strs = {"babca", "bbazb"};
    cout << minDeletionSize(strs) << endl;

    return 0;
}