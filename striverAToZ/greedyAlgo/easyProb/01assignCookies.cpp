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


/// Assume you are an awesome parent and want to give your children some cookies. 
/// However, you can only give each child at most one cookie.
/// 
/// Every child i has a greed factor g[i], which is the minimum size of a cookie that 
/// the child will be content with. Every cookie j has a size s[j]. If the cookie size 
/// is greater than or equal to the child's greed factor (s[j] >= g[i]), you can assign 
/// the cookie j to the child i, and the child will be content. Your goal is to output 
/// the maximum number of content children you can achieve.

int main()
{

    vector<int> greed = {1, 2, 3};
    vector<int> sz = {1, 1};

    cout << maxChildren(greed, sz) << endl;

    return 0;
}