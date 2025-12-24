#include <bits/stdc++.h>
using namespace std;

long long maxProfit(vector<int> &prices, vector<int> &strategy, int k)
{
    int n = prices.size();

    long long originalProfit = 0;
    for (int i = 0; i < n; i++)
    {
        originalProfit += (long long)strategy[i] * prices[i];
    }

    vector<long long> holdChange(n), sellChange(n);
    for (int i = 0; i < n; i++)
    {
        holdChange[i] = (0 - strategy[i]) * (long long)prices[i];
        sellChange[i] = (1 - strategy[i]) * (long long)prices[i];
    }

    vector<long long> holdPrefix(n + 1, 0), sellPrefix(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        holdPrefix[i + 1] = holdPrefix[i] + holdChange[i];
        sellPrefix[i + 1] = sellPrefix[i] + sellChange[i];
    }

    long long maxProfitChange = 0;
    for (int start = 0; start <= n - k; start++)
    {
        long long holdSum = holdPrefix[start + k / 2] - holdPrefix[start];

        long long sellSum = sellPrefix[start + k] - sellPrefix[start + k / 2];

        long long totalChange = holdSum + sellSum;
        maxProfitChange = max(maxProfitChange, totalChange);
    }

    return originalProfit + maxProfitChange;
}

// gpt way

long long maxProfitI(vector<int> &prices, vector<int> strategy, int k)
{
    int n = prices.size();
    vector<long long> profitSum(n + 1);
    vector<long long> priceSum(n + 1);

    for (int i = 0; i < n; i++)
    {
        profitSum[i + 1] = profitSum[i] + (long)prices[i] * strategy[i];
        priceSum[i + 1] = priceSum[i] + prices[i];
    }
    long res = profitSum[n];
    int half = k / 2;
    for (int l = 0; l + k <= n; l++)
    {
        int r = l + k;
        long leftProfit = profitSum[l];
        long rightProfit = profitSum[n] - profitSum[r];
        long changeProfit = priceSum[r] - priceSum[l + half];
        long totalProfit = leftProfit + changeProfit + rightProfit;
        res = max(res, totalProfit);
    }
    return res;
}

long long maxProfitII(vector<int> &prices, vector<int> &strategy, int k)
{
    int n = prices.size();
    vector<long long> profitSum(n + 1);
    vector<long long> priceSum(n + 1);
    for (int i = 0; i < n; i++)
    {
        profitSum[i + 1] = profitSum[i] + prices[i] * strategy[i];
        priceSum[i + 1] = priceSum[i] + prices[i];
    }
    long long res = profitSum[n];
    for (int i = k - 1; i < n; i++)
    {
        long long leftProfit = profitSum[i - k + 1];
        long long rightProfit = profitSum[n] - profitSum[i + 1];
        long long changeProfit = priceSum[i + 1] - priceSum[i - k / 2 + 1];
        res = max(res, leftProfit + changeProfit + rightProfit);
    }
    return res;
}

int main()
{

    vector<int> prices = {4, 2, 8}, strategy = {-1, 0, 1};
    int k = 2;

    cout << maxProfitII(prices, strategy, k) << endl;

    return 0;
}