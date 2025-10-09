#include <bits/stdc++.h>
using namespace std;

int maxBottlesDrunk(int numBottles, int numExchange)
{
    int full = numBottles, empty = 0, totalDrunk = 0;
    while (full > 0)
    {
        totalDrunk += full;
        empty += full;
        full = 0;

        if (empty >= numExchange)
        {
            empty -= numExchange;
            full += 1;
            numExchange++;
        }
    }
    return totalDrunk;
}

int main()
{
    int numBottles = 13, numExchange = 6;
    cout << maxBottlesDrunk(numBottles, numExchange) << endl;
    return 0;
}