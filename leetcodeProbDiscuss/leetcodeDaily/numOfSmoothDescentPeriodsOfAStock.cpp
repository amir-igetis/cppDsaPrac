#include <bits/stdc++.h>
using namespace std;

long long func(vector<int> &prices)
{
    int n = prices.size();
    int prev = 1;
    long res = 1;
    for (int i = 1; i < n; i++)
    {
        if (prices[i] == prices[i - 1] - 1)
        {
            prev++;
        }
        else
        {
            prev = 1;
        }
        res += prev;
    }
    return res;
}

int main()
{

    vector<int> prices = {8, 6, 7, 7};
    cout << func(prices) << endl;

    return 0;
}