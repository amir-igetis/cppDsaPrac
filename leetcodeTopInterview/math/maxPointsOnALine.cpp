#include <bits/stdc++.h>
using namespace std;

int getGCD(int a, int b)
{
    return b == 0 ? a : getGCD(b, a % b);
}

int maxPoints(vector<vector<int>> &points)
{
    if (points.size() < 3)
        return points.size();

    int result = 1;

    for (int i = 0; i < points.size(); i++)
    {
        unordered_map<string, int> slopeMap;
        int duplicate = 0, localMax = 0;

        for (int j = i + 1; j < points.size(); j++)
        {
            int dx = points[j][0] - points[i][0];
            int dy = points[j][1] - points[i][1];

            if (dx == 0 && dy == 0)
            {
                duplicate++;
                continue;
            }

            int g = getGCD(dx, dy);
            dx /= g;
            dy /= g;
            if (dx < 0)
            {
                dx = -dx;
                dy = -dy;
            }
            else if (dx == 0)
            {
                dy = 1;
            }

            string slope = to_string(dx) + "/" + to_string(dy);
            slopeMap[slope]++;
            localMax = max(localMax, slopeMap[slope]);
        }

        result = max(result, localMax + duplicate + 1);
    }
    return result;
}

int main()
{

    vector<vector<int>> points = {
        {1, 1}, {3, 2}, {5, 3}, {4, 1}, {2, 3}, {1, 4}};

    cout << maxPoints(points) << endl;

    return 0;
}