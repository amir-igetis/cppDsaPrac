#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int maxProf = 0;
    int mini = prices[0];
    for (int i = 1; i < prices.size(); i++)
    {
        int currProf = prices[i] - mini;
        maxProf = max(maxProf, currProf);
        mini = min(mini, prices[i]);
    }
    return maxProf;
}

int main()
{

    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << maxProfit(prices) << endl;
    return 0;
}