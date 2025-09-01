#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> p(n);
    
    if (x == 0) {
        // Place 0 at the end. The MEX will be 0 until 0 is encountered.
        for (int i = 0; i < n; ++i) {
            p[i] = i;
        }
        rotate(p.begin(), p.begin() + 1, p.end()); // Shift left by 1.
    } else if (x == n) {
        // The last MEX is n. No other MEX can be n.
        for (int i = 0; i < n; ++i) {
            p[i] = i;
        }
    } else {
        // First x positions are 0..x-1.
        for (int i = 0; i < x; ++i) {
            p[i] = i;
        }
        // Then place numbers > x, then x at the end.
        int current = x + 1;
        for (int i = x; i < n - 1; ++i) {
            if (current < n) {
                p[i] = current++;
            } else {
                // Fill remaining with any, but we should have placed all numbers.
                p[i] = i;
            }
        }
        p[n - 1] = x;
    }
    
    for (int i = 0; i < n; ++i) {
        cout << p[i] << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}