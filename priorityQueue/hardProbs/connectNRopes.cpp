#include <bits/stdc++.h>
using namespace std;

int cutRod(int price[], int n)
{
    priority_queue<int> maxHeap;
    vector<int> dp(n + 1, 0);
    for (int length = 1; length <= n; length++)
    {
        int maxProfit = 0;
        for (int cut = 1; cut <= length; cut++)
        {
            int currProfit = price[cut - 1] + dp[length - cut];
            maxHeap.push(currProfit);
        }
        maxProfit = maxHeap.top();
        dp[length] = maxProfit;
        while (!maxHeap.empty())
            maxHeap.pop();
    }
    return dp[n];
}

int main()
{
    int price[] = {3, 5, 8, 9, 10, 17, 17, 20};
    int n = 8;

    cout << cutRod(price, n) << endl;

    return 0;
}