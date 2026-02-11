#include <bits/stdc++.h>
using namespace std;

// brute tc O(n^2) & sc O(1)
int countPlatform(int n, vector<int> &arr, vector<int> &dep)
{
    int ans = 1;
    for (int i = 0; i < n; i++)
    {
        int count = 1;
        for (int j = i + 1; j < n; j++)
        {
            if ((arr[i] >= arr[j] && arr[i] <= dep[j]) ||
                (arr[j] >= arr[i] && arr[j] <= dep[i]))
                count++;
        }
        ans = max(ans, count);
    }
    return ans;
}

// optimal tc O(n logn) & sc O(1);
int countPlatformI(int n, vector<int> &arr, vector<int> &dep)
{
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());

    int platforms = 1;
    int res = 1;
    int i = 1, j = 0;
    while (i < n && j < n)
    {
        if (arr[i] <= dep[j])
        {
            platforms++;
            i++;
        }
        else
        {
            platforms--;
            j++;
        }
        res = max(res, platforms);
    }
    return res;
}

int main()
{
    vector<int> arr = {900, 945, 955, 1100, 1500, 1800};
    vector<int> dep = {920, 1200, 1130, 1150, 1900, 2000};
    int n = arr.size();
    cout << countPlatformI(n, arr, dep) << endl;

    return 0;
}