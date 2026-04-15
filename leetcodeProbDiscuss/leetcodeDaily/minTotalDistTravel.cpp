#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // ===================== RECURSION =====================
    long long minimumTotalDistance(vector<int> &robot, vector<vector<int>> &factory)
    {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        vector<int> factoryPos;
        for (auto &f : factory)
        {
            for (int i = 0; i < f[1]; i++)
            {
                factoryPos.push_back(f[0]);
            }
        }

        return solve(0, 0, robot, factoryPos);
    }

    long long solve(int i, int j, vector<int> &robot, vector<int> &factoryPos)
    {
        if (i == robot.size())
            return 0;
        if (j == factoryPos.size())
            return 1e12;

        long long assign = abs((long long)robot[i] - factoryPos[j]) +
                           solve(i + 1, j + 1, robot, factoryPos);

        long long skip = solve(i, j + 1, robot, factoryPos);

        return min(assign, skip);
    }

    // ===================== MEMOIZATION =====================
    long long minimumTotalDistanceI(vector<int> &robot, vector<vector<int>> &factory)
    {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        vector<int> factoryPos;
        for (auto &f : factory)
        {
            for (int i = 0; i < f[1]; i++)
            {
                factoryPos.push_back(f[0]);
            }
        }

        int n = robot.size(), m = factoryPos.size();
        vector<vector<long long>> memo(n, vector<long long>(m, -1));

        return solveMemo(0, 0, robot, factoryPos, memo);
    }

    long long solveMemo(int i, int j, vector<int> &robot,
                        vector<int> &factoryPos,
                        vector<vector<long long>> &memo)
    {

        if (i == robot.size())
            return 0;
        if (j == factoryPos.size())
            return 1e12;

        if (memo[i][j] != -1)
            return memo[i][j];

        long long assign = abs((long long)robot[i] - factoryPos[j]) +
                           solveMemo(i + 1, j + 1, robot, factoryPos, memo);

        long long skip = solveMemo(i, j + 1, robot, factoryPos, memo);

        return memo[i][j] = min(assign, skip);
    }

    // ===================== TABULATION =====================
    long long minimumTotalDistanceII(vector<int> &robot, vector<vector<int>> &factory)
    {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        vector<int> factoryPos;
        for (auto &f : factory)
        {
            for (int i = 0; i < f[1]; i++)
            {
                factoryPos.push_back(f[0]);
            }
        }

        int n = robot.size(), m = factoryPos.size();
        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 0));

        for (int i = 0; i < n; i++)
        {
            dp[i][m] = 1e12;
        }

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {

                long long assign =
                    abs((long long)robot[i] - factoryPos[j]) +
                    dp[i + 1][j + 1];

                long long skip = dp[i][j + 1];

                dp[i][j] = min(assign, skip);
            }
        }

        return dp[0][0];
    }

    // ===================== SPACE OPTIMIZED =====================
    long long minimumTotalDistanceIII(vector<int> &robot, vector<vector<int>> &factory)
    {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        vector<int> factoryPos;
        for (auto &f : factory)
        {
            for (int i = 0; i < f[1]; i++)
            {
                factoryPos.push_back(f[0]);
            }
        }

        int n = robot.size(), m = factoryPos.size();

        vector<long long> next(m + 1, 0), curr(m + 1, 0);
        curr[m] = 1e12;

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {

                long long assign =
                    abs((long long)robot[i] - factoryPos[j]) +
                    next[j + 1];

                long long skip = curr[j + 1];

                curr[j] = min(assign, skip);
            }
            next = curr;
        }

        return curr[0];
    }
};

// ===================== MAIN =====================
int main()
{
    Solution obj;

    vector<int> robots = {0, 4, 6};
    vector<vector<int>> factories = {{2, 2}, {6, 2}};

    cout << obj.minimumTotalDistanceIII(robots, factories) << endl;

    return 0;
}