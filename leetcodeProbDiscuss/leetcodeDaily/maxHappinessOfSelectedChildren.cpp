#include <bits/stdc++.h>
using namespace std;

// sort + greedy
long long maximumHappinessSum(vector<int> &happiness, int k)
{
    sort(happiness.begin(), happiness.end(), greater<int>());
    long long totalHappiness = 0;
    int turns = 0;

    for (int i = 0; i < k; i++)
    {
        totalHappiness += max(happiness[i] - turns, 0);
        turns++;
    }
    return totalHappiness;
}

// pq + greedy
long long maximumHappinessSumI(vector<int> &happiness, int k)
{
    priority_queue<int> pq;
    for (const auto &h : happiness)
        pq.push(h);
    long long totalHappiness = 0;
    int turns = 0;
    for (int i = 0; i < k; i++)
    {
        totalHappiness += max(pq.top() - turns, 0);
        pq.pop();
        turns++;
    }

    return totalHappiness;
}

int main()
{

    vector<int> happiness = {1, 2, 3};
    int k = 2;

    cout << maximumHappinessSum(happiness, k) << endl;

    return 0;
}