#include <bits/stdc++.h>
using namespace std;

double angleClock(int hour, int minutes)
{
    double x = hour + (minutes / 60.0);
    double diff = fmod(11.0 * x, 12.0);
    return min(diff, 12.0 - diff) * 30.0;
}

int main()
{
    int hour = 12, minutes = 30;
    cout << angleClock(hour, minutes) << endl;

    return 0;
}