#include <bits/stdc++.h>
using namespace std;

// Function to check if an array is sorted in non-decreasing order
bool isSorted(vector<int> &arr)
{
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] < arr[i - 1])
            return false;
    }
    return true;
}

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int &x : a)
        cin >> x;

    int b;
    cin >> b; // Since m = 1, we only read one value

    // Case 1: Check if the original array is already sorted
    if (isSorted(a))
    {
        cout << "YES\n";
        return;
    }

    // Case 2: Check if we can make the transformed array sorted
    vector<int> transformed(n);
    for (int i = 0; i < n; i++)
    {
        transformed[i] = b - a[i];
    }

    if (isSorted(transformed))
    {
        cout << "YES\n";
        return;
    }

    // Case 3: Check if we can mix both strategies
    vector<int> mixed;
    for (int i = 0; i < n; i++)
    {
        mixed.push_back(a[i]);
        mixed.push_back(b - a[i]);
    }

    sort(mixed.begin(), mixed.end());

    if (isSorted(mixed))
    {
        cout << "YES\n";
        return;
    }

    cout << "NO\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
