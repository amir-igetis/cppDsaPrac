#include <bits/stdc++.h>
using namespace std;

int minFlips(string s)
{
    int n = s.size();
    int ans1 = 0, ans2 = 0, ans = INT_MAX;
    for (int i = 0; i < 2 * n; i++)
    {
        if (i < n)
            s[i] -= '0'; // make '1' and '0' to be integer 1 and 0.
        if (i % 2 != s[i % n])
            ++ans1;
        if ((i + 1) % 2 != s[i % n])
            ++ans2;
        if (i >= n)
        {
            if ((i - n) % 2 != s[i - n])
                --ans1;
            if ((i - n + 1) % 2 != s[i - n])
                --ans2;
        }
        if (i >= n - 1)
            ans = min({ans1, ans2, ans});
    }
    return ans;
}

// another solution tc O(n) and sc O(1)
int minFlipsI(string s)
{
    int n = s.size();
    vector<vector<int>> cnt(2, vector<int>(2, 0));
    // cnt[0][0] = number of '0' in even positions
    // cnt[0][1] = number of '0' in odd positions
    // cnt[1][0] = number of '1' in even positions
    // cnt[1][1] = number of '1' in odd positions
    for (int i = 0; i < n; i++)
    {
        cnt[s[i] - '0'][i % 2]++;
    }
    int ans = cnt[1][0] + cnt[0][1];
    // cost to make all '0' in even positions and all '1' in odd positions
    ans = min(ans, cnt[0][0] + cnt[1][1]);
    // cost to make all '1' in even positions and all '0' in odd positions
    for (int i = 0; i < n; i++)
    {
        cnt[s[i] - '0'][i % 2]--;
        cnt[s[i] - '0'][(n + i) % 2]++;
        // sending this character at the end of the string
        ans = min(ans, cnt[1][0] + cnt[0][1]);
        ans = min(ans, cnt[0][0] + cnt[1][1]);
    }
    return ans;
}

int main()
{

    string s = "111000";
    cout << minFlipsI(s) << endl;

    return 0;
}