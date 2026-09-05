#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> pos0, pos1;
    long long inversions = 0;
    int ones = 0;
    
    // Read array, partition indices and calculate initial inversions
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] == 1) {
            pos1.push_back(i);
            ones++;
        } else {
            pos0.push_back(i);
            inversions += ones;
        }
    }
    
    string s;
    cin >> s;

    // Track the active segment bounds in the `pos1` and `pos0` arrays
    int p1_start = 0, p1_end = (int)pos1.size() - 1;
    int p0_start = 0, p0_end = (int)pos0.size() - 1;

    // A helper function to truncate newly created leading 0s or trailing 1s
    auto update_bounds = [&]() {
        while (p0_start <= p0_end && p1_start <= p1_end && pos0[p0_start] < pos1[p1_start]) {
            p0_start++;
        }
        while (p0_start <= p0_end && p1_start <= p1_end && pos1[p1_end] > pos0[p0_end]) {
            p1_end--;
        }
    };

    update_bounds();
    cout << inversions << (n == 0 ? "" : " ");

    for (int i = 0; i < n; ++i) {
        // If the active range is empty, inversion pairs are depleted
        if (inversions == 0 || p0_start > p0_end || p1_start > p1_end) {
            inversions = 0;
            cout << 0 << (i == n - 1 ? "" : " ");
            continue;
        }
        
        long long active_zeros = p0_end - p0_start + 1;
        long long active_ones = p1_end - p1_start + 1;

        if (s[i] == '1') {
            // Bubble operation: removes the top row (the very first '1')
            inversions -= active_zeros;
            p1_start++;
        } else {
            // Reverse bubble operation: removes the left column (the very last '0')
            inversions -= active_ones;
            p0_end--;
        }
        
        update_bounds();
        cout << inversions << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}