#include <bits/stdc++.h>
using namespace std;

bool check(vector<long long> &arr, int side, int k, long long limit)
{
    long long perimeter = 4LL * side;
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        long long start = arr[i];
        long long end = start + perimeter - limit;
        long long cur = start;

        for (int cnt = 0; cnt < k - 1; cnt++)
        {
            auto it = lower_bound(arr.begin(), arr.end(), cur + limit);

            if (it == arr.end() || *it > end)
            {
                cur = -1;
                break;
            }

            cur = *it;
        }

        if (cur >= 0)
            return true;
    }

    return false;
}

int maxDistance(int side, vector<vector<int>> &points, int k)
{
    vector<long long> arr;

    // Step 1: map to perimeter
    for (auto &p : points)
    {
        int x = p[0], y = p[1];

        if (x == 0)
            arr.push_back(y);
        else if (y == side)
            arr.push_back(side + x);
        else if (x == side)
            arr.push_back(3LL * side - y);
        else
            arr.push_back(4LL * side - x);
    }

    sort(arr.begin(), arr.end());

    long long lo = 1, hi = side;
    int ans = 0;

    while (lo <= hi)
    {
        long long mid = (lo + hi) / 2;
        if (check(arr, side, k, mid))
        {
            ans = mid;
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }

    return ans;
}

int main()
{

    vector<vector<int>> points = {{0, 2}, {2, 0}, {2, 2}, {0, 0}};
    int k = 4;
    int side = 2;

    cout << maxDistance(side, points, k) << endl;

    return 0;
}