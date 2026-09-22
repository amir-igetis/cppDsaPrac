#include <bits/stdc++.h>
using namespace std;

int solve(int n, const vector<long long> &a)
{
    int ballast = 0;
    vector<long long> b(n);

    // Transform a_i to b_i = a_i - i (using 1-based index conceptually)
    for (int i = 0; i < n; ++i)
    {
        b[i] = a[i] - (i + 1);
    }

    // Sort and remove duplicates to find unique available values
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());

    // Find the longest contiguous sequence of consecutive integers
    int max_len = 1;
    int current_len = 1;

    for (size_t i = 1; i < b.size(); ++i)
    {
        if (b[i] == b[i - 1] + 1)
        {
            current_len++;
        }
        else
        {
            max_len = max(max_len, current_len);
            current_len = 1;
        }
    }
    max_len = max(max_len, current_len);

    return max_len;
}

int main()
{
    // Optimize standard I/O operations for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t)
    {
        while (t--)
        {
            int n;
            cin >> n;
            vector<long long> a(n);
            for (int i = 0; i < n; ++i)
            {
                cin >> a[i];
            }
            // Output the returned result from the solve function
            cout << solve(n, a) << "\n";
        }
    }

    return 0;
}