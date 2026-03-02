#include <bits/stdc++.h>
using namespace std;

int countBits(int num)
{
    int count = 0;
    while (num > 0)
    {
        count++;
        num &= (num - 1);
    }
    return count;
}

bool compare(int a, int b)
{
    int bitCountA = countBits(a);
    int bitCountB = countBits(b);

    if (bitCountA == bitCountB)
        return a < b;

    return bitCountA < bitCountB;
}

// Brian Kerninghan's Algo tc & sc O(n * logN) , O(n) or O(logN)
vector<int> sortByBits(vector<int> &arr)
{
    sort(arr.begin(), arr.end(), compare);
    return arr;
}

int main()
{
    vector<int> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    vector<int> ans = sortByBits(arr);
    for (auto &i : ans)
        cout << i << " ";
    cout << endl;

    return 0;
}