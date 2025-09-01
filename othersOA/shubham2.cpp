#include <bits/stdc++.h>
using namespace std;

int getMinSeconds(int a, vector<int> coordinates)
{
    sort(coordinates.begin(), coordinates.end());
    int n = coordinates.size();
    int minTime = INT_MAX;

    for (int i = 0; i <= n - a; i++)
    {
        int leftMost = coordinates[i];
        int rightMost = coordinates[i + a - 1];

        int time1 = abs(leftMost) + (rightMost - leftMost);

        int time2 = abs(rightMost) + (rightMost - leftMost);

        minTime = min(minTime, min(time1, time2));
    }

    return minTime;
}

int main()
{
    // int a = 3;
    // vector<int> coordinates = {-30, -10, 10, 20, 50};
    int a = 1;
    vector<int> coordinates = {1, 1, 0};
    cout << getMinSeconds(a, coordinates);
    return 0;
}