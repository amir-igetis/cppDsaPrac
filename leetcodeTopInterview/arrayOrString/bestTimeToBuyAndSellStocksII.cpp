#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int maxProf = 0;
    int n = prices.size();

    for (int i = 1; i < n; i++)
    {
        if (prices[i] > prices[i - 1])
            maxProf += prices[i] - prices[i - 1];
    }
    return maxProf;
}

int main()
{

    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << maxProfit(prices) << endl;
    return 0;
}