#include <bits/stdc++.h>
using namespace std;

// enumeration
int maxDistance(vector<int> &colors)
{
    int n = colors.size();
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (colors[i] != colors[j])
                res = max(res, j - i);
        }
    }
    return res;
}

// O(n)
int maxDistanceI(vector<int> &colors)
{
    int n = colors.size();
    int maxDist = 0;

    // Compare with first house
    for (int j = n - 1; j >= 0; j--)
    {
        if (colors[j] != colors[0])
        {
            maxDist = j; // distance = j - 0
            break;
        }
    }

    // Compare with last house
    for (int i = 0; i < n; i++)
    {
        if (colors[i] != colors[n - 1])
        {
            maxDist = max(maxDist, (n - 1) - i);
            break;
        }
    }

    return maxDist;
}

int main()
{
    vector<int> colors = {1, 1, 1, 6, 1, 1, 1};
    cout << maxDistanceI(colors) << endl;

    return 0;
}