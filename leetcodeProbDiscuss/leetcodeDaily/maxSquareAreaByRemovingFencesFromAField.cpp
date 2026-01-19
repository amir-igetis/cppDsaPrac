#include <bits/stdc++.h>
using namespace std;

unordered_set<int> getEdges(vector<int> &fences, int border)
{
    unordered_set<int> st;
    fences.push_back(1);
    fences.push_back(border);
    sort(fences.begin(), fences.end());
    for (int i = 0; i < fences.size(); i++)
    {
        for (int j = i + 1; j < fences.size(); j++)
            st.insert(fences[j] - fences[i]);
    }
    return st;
}

// tc and sc O(h^2+v^2).
int maximizeSquareArea(int m, int n, vector<int> &hFences, vector<int> &vFences)
{
    int mod = 1e9 + 7;
    auto hEdges = getEdges(hFences, m);
    auto vEdges = getEdges(vFences, n);
    int res = 0;
    for (auto e : hEdges)
    {
        if (vEdges.count(e))
            res = max(res, e);
    }
    if (res == 0)
        res = -1;
    else
        res = 1ll * res * res % mod;
    return res;
}

int main()
{

    int m = 4, n = 3;
    vector<int> hFence = {2, 3}, vFence = {2};
    cout << maximizeSquareArea(m, n, hFence, vFence) << endl;

    return 0;
}