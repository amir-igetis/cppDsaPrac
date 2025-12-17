#include <bits/stdc++.h>
using namespace std;

int maxProfit(int n, vector<int> &present, vector<int> &future,
              vector<vector<int>> &hierarchy, int budget)
{
    vector<vector<int>> g(n);
    for (auto &e : hierarchy)
        g[e[0] - 1].push_back(e[1] - 1);

    auto dfs = [&](auto &&self, int u)
        -> tuple<vector<int>, vector<int>, int>
    {
        int cost = present[u];
        int dCost = present[u] / 2;

        vector<int> dp0(budget + 1, 0);
        vector<int> dp1(budget + 1, 0);
        vector<int> subProfit0(budget + 1, 0);
        vector<int> subProfit1(budget + 1, 0);

        int uSize = cost;

        for (int v : g[u])
        {
            auto res = self(self, v);
            auto &subDp0 = get<0>(res);
            auto &subDp1 = get<1>(res);
            int vSize = get<2>(res);

            uSize += vSize;

            for (int i = budget; i >= 0; i--)
            {
                for (int sub = 0; sub <= min(vSize, i); sub++)
                {
                    subProfit0[i] = max(subProfit0[i],
                                        subProfit0[i - sub] + subDp0[sub]);
                    subProfit1[i] = max(subProfit1[i],
                                        subProfit1[i - sub] + subDp1[sub]);
                }
            }
        }

        for (int i = 0; i <= budget; i++)
        {
            dp0[i] = dp1[i] = subProfit0[i];

            if (i >= dCost)
                dp1[i] = max(dp1[i],
                             subProfit1[i - dCost] + future[u] - dCost);

            if (i >= cost)
                dp0[i] = max(dp0[i],
                             subProfit1[i - cost] + future[u] - cost);
        }

        return make_tuple(dp0, dp1, uSize);
    };

    return get<0>(dfs(dfs, 0))[budget];
}

int main()
{
    int n = 2;
    vector<int> present = {1, 2}, future = {4, 3};
    vector<vector<int>> hierarchy = {{1, 2}};
    int budget = 3;

    cout << maxProfit(n, present, future, hierarchy, budget);
}
