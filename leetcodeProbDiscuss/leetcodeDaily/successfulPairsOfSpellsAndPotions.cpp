#include <bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> &arr, long long target)
{
    int l = 0, r = arr.size();
    while (l < r)
    {
        int mid = l + (r - l) / 2;
        if (arr[mid] < target)
        {
            l = mid + 1;
        }
        else
        {
            r = mid;
        }
    }
    return l;
}

vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success)
{
    sort(potions.begin(), potions.end());
    int n = spells.size(), m = potions.size();
    vector<int> res(n);

    for (int i = 0; i < n; i++)
    {
        long long spell = spells[i];
        long long minPotion = (success + spell - 1) / spell;
        int idx = lowerBound(potions, minPotion);
        res[i] = m - idx;
    }
    return res;
}

int main()
{

    vector<int> spells = {5, 1, 3}, potions = {1, 2, 3, 4, 5};
    int success = 7;

    vector<int> ans = successfulPairs(spells, potions, success);

    for (auto &i : ans)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}