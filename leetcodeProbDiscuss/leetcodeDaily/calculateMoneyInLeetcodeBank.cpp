#include <bits/stdc++.h>
using namespace std;

int totalMoney(int n)
{
    int fullWeeks = n / 7, remainingDays = n % 7;
    int totalMoney = 28 * fullWeeks + 7 * (fullWeeks - 1) * fullWeeks / 2;
    totalMoney += (fullWeeks + 1 + fullWeeks + remainingDays) * remainingDays / 2;
    return totalMoney;
}

int main()
{

    int n = 4;
    cout << totalMoney(n) << endl;

    return 0;
}