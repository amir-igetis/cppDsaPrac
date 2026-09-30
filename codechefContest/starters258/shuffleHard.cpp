#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> q(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> q[i];
    }

    // Condition 1: The last K elements must be strictly increasing
    for (int i = n - k + 1; i < n; i++) {
        if (q[i] >= q[i + 1]) {
            cout << 0 << "\n";
            return;
        }
    }

    // Determine L_i and R_i for each element
    vector<int> L(n + 1, 1);
    vector<int> R(n + 1);
    for (int i = 1; i <= n; i++) {
        R[i] = min(n, i + k - 1);
        
        // Find the nearest left element that is greater than Q[i]
        int j_star = -1;
        for (int j = i - 1; j >= 1; j--) {
            if (q[j] > q[i]) {
                j_star = j;
                break;
            }
        }
        if (j_star != -1) {
            L[i] = j_star + k;
        }
        
        // If an interval is inherently invalid
        if (L[i] > R[i]) {
            cout << 0 << "\n";
            return;
        }
    }

    // Count the perfect matchings mapping values to [L_i, R_i]
    vector<int> count_L(n + 2, 0);
    for (int i = 1; i <= n; i++) {
        count_L[L[i]]++;
    }

    long long ans = 1;
    int available = 0;
    int needed = 0;
    
    // Check matchings by tracking active capacities bounds
    vector<int> at_R(n + 2, 0);
    for(int i = 1; i <= n; i++) {
        at_R[R[i]]++;
    }

    // Working forward assigning valid spots
    for (int x = 1; x <= n; x++) {
        available += count_L[x];
        if (available <= 0) {
            ans = 0;
            break;
        }
        ans = (ans * available) % MOD;
        available--; 
        
        // We drop constraints sequentially mimicking interval consumption capacity
    }
    
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while (t--) solve();
    }
    return 0;
}