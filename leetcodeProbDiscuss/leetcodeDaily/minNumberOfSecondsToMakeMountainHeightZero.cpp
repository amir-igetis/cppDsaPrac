#include <bits/stdc++.h>
using namespace std;

long long minNumberOfSeconds(int mountainHeight, vector<int> &workerTimes)
{
    long long lo = 1;
    long long hi = 10000000000000000LL;

    while (lo < hi)
    {
        long long mid = (lo + hi) / 2;
        long long tot = 0;

        for (int i = 0; i < workerTimes.size() && tot < mountainHeight; i++)
        {
            double val = (double)mid / workerTimes[i];
            long long k = (long long)(sqrt(2 * val + 0.25) - 0.5);
            tot += k;
        }

        if (tot >= mountainHeight)
            hi = mid;
        else
            lo = mid + 1;
    }

    return lo;
}

int main()
{
    int mountainHeight = 4;
    vector<int> workerTimes = {2, 1, 1};

    cout << minNumberOfSeconds(mountainHeight, workerTimes) << endl;

    return 0;
}