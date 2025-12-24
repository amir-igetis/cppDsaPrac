#include <bits/stdc++.h>
using namespace std;

int isUnsorted(vector<string> &strs, int j)
{
    for (int i = 1; i < strs.size(); i++)
    {
        if (strs[i][j] < strs[i - 1][j])
            return 1;
    }
    return 0;
}

int minDeletionSize(vector<string> &strs)
{
    int res = 0;
    for (int j = 0; j < strs[0].length(); j++)
    {
        res += isUnsorted(strs, j);
    }
    return res;
}

int main()
{

    vector<string> strs = {"cba", "daf", "ghi"};
    cout << minDeletionSize(strs) << endl;

    return 0;
}