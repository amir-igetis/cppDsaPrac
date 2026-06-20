#include <bits/stdc++.h>
using namespace std;

int largestAltitude(vector<int> &gain)
{
    int currAltitude = 0;
    int highestPoint = currAltitude;
    for (auto &altitudeGain : gain)
    {
        currAltitude += altitudeGain;
        highestPoint = max(highestPoint, currAltitude);
    }
    return highestPoint;
}

int main()
{

    vector<int> gain = {-5, 1, 5, 0, -7};
    cout << largestAltitude(gain) << endl;

    return 0;
}