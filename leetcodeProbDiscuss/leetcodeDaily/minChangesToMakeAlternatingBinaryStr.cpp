#include <bits/stdc++.h>
using namespace std;

int minOperations(string s)
{
    int res = 0;
    int n = s.size();
    for (int i = 1; i < n; i++)
    {
        if (s[i] - '0' != i % 2)
            res++;
    }
    return min(res, n - res);
}

// another solution

int count(string s, char ch)
{
    int count = 0;
    for (int i = 1; i < s.size(); i++)
    {
        char curr = s[i];
        if (curr == ch)
        {
            count++;
            ch = ch == '0' ? '1' : '0';
        }
        else
        {
            ch = curr;
        }
    }
    return count;
}

int minOperationsI(string s)
{
    char ch = s[0];
    int count1 = count(s, ch);
    int count2 = count(s, ch == '0' ? '1' : '0') + 1;
    return min(count1, count2);
}

int main()
{
    string s = "0100";
    cout << minOperations(s) << endl;

    return 0;
}