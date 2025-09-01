#include <bits/stdc++.h>
using namespace std;

int func(int n, string s)
{
    vector<string> res;

    for (int i = 0; i < s.size(); i++)
    {
        string str = s;
        str[i] = (str[i] == '0') ? '1' : '0';
        res.push_back(str);
    }

    int count = 0;
    for (const string &str : res)
    {
        for (char c : str)
            if (c == '1')
                count++;
    }

    return count;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        string s;
        cin >> n >> s;

        // vector<int> res = func(n, s);
        // // cout << func(n, s) << endl;

        // for (auto &i : res)
        // {
        //     cout << i << " ";
        // }
        // cout << endl;

        cout << func(n, s) << endl;
    }

    return 0;
}
