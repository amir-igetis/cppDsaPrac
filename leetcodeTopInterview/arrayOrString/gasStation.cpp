#include <bits/stdc++.h>
using namespace std;

int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{

    int n = gas.size();
    int totalGas = 0, totalCost = 0, tank = 0, start = 0;
    for (int i = 0; i < n; i++)
    {
        totalGas += gas[i];
        totalCost += cost[i];
        tank += gas[i] - cost[i];
        if (tank < 0)
        {
            start = i + 1;
            tank = 0;
        }
    }
    if (totalGas < totalCost)
        return -1;

    return start;
}

int main()
{

    vector<int> gas = {1, 2, 3, 4, 5}, cost = {3, 4, 5, 1, 2};

    cout << canCompleteCircuit(gas, cost) << endl;
    return 0;
}