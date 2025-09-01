#include <bits/stdc++.h>
using namespace std;

// int minSensors(int n, int m, int k)
// {
//     int ans = INT_MAX;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             int chevDist = max(| i - i |, | j - j |);
//             ans = min(chevDist, ans);
//         }
//     }

//     return ans;
// }

// working, see if it gives TLE
bool covers(int sr, int sc, int r, int c, int k)
{
    return max(abs(sr - r), abs(sc - c)) <= k;
}

bool checkCovered(vector<pair<int, int>> &sensors, int n, int m, int k)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            bool ok = false;
            for (auto &s : sensors)
            {
                if (covers(s.first, s.second, i, j, k))
                {
                    ok = true;
                    break;
                }
            }
            if (!ok)
                return false; // cell (i,j) not covered
        }
    }
    return true;
}

int minSensorsBrute(int n, int m, int k)
{
    int total = n * m;
    int best = INT_MAX;

    // Try all subsets
    for (int mask = 1; mask < (1 << total); mask++)
    {
        vector<pair<int, int>> sensors;
        for (int pos = 0; pos < total; pos++)
        {
            if (mask & (1 << pos))
            {
                int r = pos / m;
                int c = pos % m;
                sensors.push_back({r, c});
            }
        }

        if (checkCovered(sensors, n, m, k))
        {
            best = min(best, (int)sensors.size());
        }
    }
    return best;
}

// advance soln

// works great
int minSensorsI(int n, int m, int k)
{
    int cover = 2 * k + 1;
    int rows = (n + cover - 1) / cover; // ceil(n / cover)
    int cols = (m + cover - 1) / cover; // ceil(m / cover)
    return rows * cols;
}

// not working
int minSensorsII(int n, int m, int k)
{
    int cover = 2 * k + 1;
    int rowsNeed;

    if (n % cover == 0)
    {
        rowsNeed = n / cover;
    }
    else
    {
        rowsNeed = (n / cover) + 1;
    }

    int colsNeed;
    if (m % cover == 0)
    {
        colsNeed = m / cover;
    }
    else
    {
        colsNeed = (m / cover) + 1;
    }

    int res = rowsNeed + colsNeed;

    return res;
}

int main()
{

    int n = 2, m = 2, k = 2;
    cout << minSensorsBrute(n, m, k) << endl;
    return 0;
}