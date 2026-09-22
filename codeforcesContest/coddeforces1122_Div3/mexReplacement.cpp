#include <bits/stdc++.h>
using namespace std;

const long long MAX_REQ = 200000000000005LL; // Safely larger than total possible elements (2e5 * 1e9)

// Predicate to check if we can form the target MEX value V
bool can_form(long long V, const vector<pair<long long, long long>> &A, const vector<long long> &suf)
{
    if (V == 0)
        return true;

    long long req = 1;
    // Elements >= V can only be used by melting them into 0s
    auto it = lower_bound(A.begin(), A.end(), make_pair(V, -1LL));
    int idx = distance(A.begin(), it);
    long long excess_zeroes = suf[idx];

    long long current_val = V - 1;
    int ptr_idx = idx;

    while (current_val >= 1)
    {
        if (req > MAX_REQ)
            return false;

        long long count = 0;
        if (ptr_idx > 0)
        {
            if (A[ptr_idx - 1].first == current_val)
            {
                count = A[ptr_idx - 1].second;
                ptr_idx--;
            }
        }

        if (count >= req)
        {
            excess_zeroes += (count - req);
            current_val--;
        }
        else
        {
            long long deficit = req - count;
            req += deficit;
            current_val--;

            // O(1) jump optimization over gaps of completely missing elements
            long long next_present = 1;
            if (ptr_idx > 0)
            {
                next_present = max(1LL, A[ptr_idx - 1].first + 1);
            }

            if (current_val >= next_present)
            {
                long long hole_size = current_val - next_present + 1;
                if (hole_size >= 55)
                    return false; // Prevents bit-shift overflow
                if (req > (MAX_REQ >> hole_size))
                    return false;
                req <<= hole_size;
                current_val = next_present - 1;
            }
        }
    }

    long long count_0 = 0;
    if (ptr_idx > 0 && A[ptr_idx - 1].first == 0)
    {
        count_0 = A[ptr_idx - 1].second;
    }

    // Check if the original 0s plus any melted excess elements cover the 0s requirement
    return (count_0 + excess_zeroes) >= req;
}

void solve()
{
    int n;
    cin >> n;
    vector<pair<long long, long long>> A(n);
    long long max_x = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i].first >> A[i].second;
        if (A[i].first > max_x)
        {
            max_x = A[i].first;
        }
    }
    sort(A.begin(), A.end());

    // Suffix sums array to evaluate available elements in O(1)
    vector<long long> suf(n + 1, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        suf[i] = suf[i + 1] + A[i].second;
    }

    // Binary Search for the maximum constructable value
    long long low = 0, high = 2000000000LL;
    long long best_V = 0;

    while (low <= high)
    {
        long long mid = low + (high - low) / 2;
        if (can_form(mid, A, suf))
        {
            best_V = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    long long mexoramax = max(best_V, max_x);
    cout << mexoramax << "\n";
}

int main()
{
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t)
    {
        while (t--)
        {
            solve();
        }
    }
    return 0;
}