#include <bits/stdc++.h>
using namespace std;

///  greedy tc O(n) sc O(1)
int minimumPushes(string word)
{
    int n = word.length();
    int ans = 0;
    for (int i = 0; i < n; i++)
        ans += i / 8 + 1;

    return ans;
}

/// math tc & sc O(1)
int minimumPushesI(string word)
{
    int n = word.length();
    int m = (n - 1) / 8 + 1;
    return m * (m - 1) * 4 + (n - (m - 1) * 8) * m;
}

int main()
{
    string word = "abcde";

    cout << minimumPushes(word) << endl;

    return 0;
}