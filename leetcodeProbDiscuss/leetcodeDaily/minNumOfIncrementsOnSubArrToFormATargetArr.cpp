#include <bits/stdc++.h>
using namespace std;

int minNumberOperations(vector<int> &target)
{
    int operations = target[0];

    for (int i = 1; i < target.size(); i++)
    {
        if (target[i] > target[i - 1])
            operations += target[i] - target[i - 1];
    }
    return operations;
}

// another soln
int minNumberOperationsI(vector<int> &target)
{
    int min = target[0];
    for (int i = 1; i < target.size(); i++)
    {
        min += max(target[i] - target[i - 1], 0);
    }
    return min;
}

int main()
{

    vector<int> target = {1, 2, 3, 2, 1};
    cout << minNumberOperations(target) << endl;

    return 0;
}