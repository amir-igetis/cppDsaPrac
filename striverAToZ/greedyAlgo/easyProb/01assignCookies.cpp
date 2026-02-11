#include <bits/stdc++.h>
using namespace std;

int maxChildren(vector<int> &greed, vector<int> &sz)
{
    int n = greed.size();
    int m = sz.size();
    int count = 0;
    sort(greed.begin(), greed.end());
    sort(sz.begin(), sz.end());
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (greed[i] <= sz[j])
        {
            count++;
            i++;
            j++;
        }
        else
        {
            j++;
        }
    }
    return count;
}

int main()
{

    vector<int> greed = {1, 2, 3};
    vector<int> sz = {1, 1};

    cout << maxChildren(greed, sz) << endl;

    return 0;
}