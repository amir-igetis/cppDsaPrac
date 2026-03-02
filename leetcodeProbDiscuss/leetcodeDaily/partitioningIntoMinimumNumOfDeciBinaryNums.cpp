#include <bits/stdc++.h>
using namespace std;

int minPartitions(string n)
{
    int res = 0;
    for (int i = 0; i < n.size(); i++)
        res = max(res, n[i] - '0');

    return res;
}

int main()
{
    string n = "32";
    cout << minPartitions(n) << endl;

    return 0;
}