#include <bits/stdc++.h>
using namespace std;

int countTrapezoids(vector<vector<int>> &points)
{
    unordered_map<int, int> mp;
    const int mod = 1e9 + 7;
    long long ans = 0, sum = 0;
    for (auto &i : points)
    {
        mp[i[1]]++;
    }

    for (auto &i : mp)
    {
        int pNum = i.second;
        long long edge = (long long)pNum * (pNum - 1) / 2;
        ans += edge * sum;
        sum += edge;
    }

    return ans % mod;
}

int main()
{

    vector<vector<int>> points = {{1, 0}, {2, 0}, {3, 0}, {2, 2}, {3, 2}};
    cout << countTrapezoids(points) << endl;

    return 0;
}