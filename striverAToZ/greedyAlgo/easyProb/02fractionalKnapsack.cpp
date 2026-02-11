#include <bits/stdc++.h>
using namespace std;

struct Item
{
    int value;
    int weight;
};

bool comp(Item a, Item b)
{
    double r1 = (double)a.value / (double)a.weight;
    double r2 = (double)b.value / (double)b.weight;
    return r1 > r2;
}

double fractionalKnapsack(int w, Item arr[], int n)
{
    sort(arr, arr + n, comp);
    int currWeight = 0;
    double finalVal = 0.0;
    for (int i = 0; i < n; i++)
    {
        if (currWeight + arr[i].weight <= w)
        {
            currWeight += arr[i].weight;
            finalVal += arr[i].value;
        }
        else
        {
            int remain = w - currWeight;
            finalVal += (arr[i].value / (double)arr[i].weight) * (double)remain;
            break;
        }
    }
    return finalVal;
}

int main()
{
    int n = 3, weight = 50; // Number of items and capacity of knapsack
    // Item values and weights
    Item arr[n] = {{100, 20}, {60, 10}, {120, 30}};
    cout << fractionalKnapsack(weight, arr, n) << endl;

    return 0;
}