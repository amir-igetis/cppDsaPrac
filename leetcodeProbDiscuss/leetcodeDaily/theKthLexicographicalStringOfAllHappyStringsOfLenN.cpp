#include <bits/stdc++.h>
using namespace std;

// ---------- Math based solution ----------
string getHappyString(int n, int k)
{
    int prem = 1 << (n - 1); // 2^(n-1)

    if (k > 3 * prem)
        return "";

    char ch = 'a' + (k - 1) / prem;
    string sb(1, ch);

    while (prem > 1)
    {
        k = (k - 1) % prem + 1;
        prem >>= 1;

        if ((k - 1) / prem == 0)
            ch = 'a' + (ch == 'a' ? 1 : 0);
        else
            ch = 'b' + (ch != 'c' ? 1 : 0);

        sb.push_back(ch);
    }

    return sb;
}

// ---------- DFS solution ----------
int countHappy = 0;
string result = "";

void dfs(string curr, int n, int k)
{
    if (curr.size() == n)
    {
        countHappy++;
        if (countHappy == k)
            result = curr;
        return;
    }

    vector<char> chars = {'a', 'b', 'c'};

    for (char c : chars)
    {
        if (!curr.empty() && curr.back() == c)
            continue;

        dfs(curr + c, n, k);

        if (!result.empty()) // stop early
            return;
    }
}

string getHappyStringI(int n, int k)
{
    countHappy = 0;
    result = "";
    dfs("", n, k);
    return result;
}

int main()
{
    int n = 3, k = 9;

    cout << getHappyString(n, k) << endl;
    cout << getHappyStringI(n, k) << endl;

    return 0;
}