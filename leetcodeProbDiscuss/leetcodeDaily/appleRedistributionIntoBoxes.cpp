#include <bits/stdc++.h>
using namespace std;

// My soln
int minimumBoxes(vector<int> &apple, vector<int> &capacity)
{
    int totalWeight = 0;
    for (auto &i : apple)
        totalWeight += i;

    sort(capacity.begin(), capacity.end());
    int res = 0, i = capacity.size() - 1;
    while (i >= 0 && totalWeight > 0)
    {
        totalWeight -= capacity[i];
        res++;
        i--;
    }
    return res;
}

// Leetcode soln (greedy)
int minimumBoxesI(vector<int> &apple, vector<int> &capacity)
{
    int sum = accumulate(apple.begin(), apple.end(), 0);
    sort(capacity.begin(), capacity.end(), greater<int>());
    int need = 0;
    while (sum > 0)
    {
        sum -= capacity[need];
        need += 1;
    }
    return need;
}

int main()
{
    vector<int> apple = {1, 3, 2}, capacity = {4, 2, 1, 5, 2};
    cout << minimumBoxesI(apple, capacity) << endl;

    return 0;
}