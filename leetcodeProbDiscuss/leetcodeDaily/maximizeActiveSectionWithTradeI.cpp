#include <bits/stdc++.h>
using namespace std;

// Greedy: TC = O(n), SC = O(k)
int maxActiveSectionsAfterTrade(string s) {
    int n = s.size();

    int cnt1 = 0;
    for (char c : s) {
        if (c == '1') cnt1++;
    }

    vector<int> zeroBlocks;

    int i = 0;
    while (i < n) {
        int start = i;
        while (i < n && s[i] == s[start]) {
            i++;
        }

        if (s[start] == '0') {
            zeroBlocks.push_back(i - start);
        }
    }

    int m = zeroBlocks.size();
    if (m < 2) return cnt1;

    int bestGain = 0;
    for (int j = 0; j < m - 1; j++) {
        bestGain = max(bestGain, zeroBlocks[j] + zeroBlocks[j + 1]);
    }

    return cnt1 + bestGain;
}

// Space Optimized: TC = O(n), SC = O(1)
int maxActiveSectionsAfterTradeI(string s) {
    int n = s.size();

    int cnt1 = 0;
    for (char c : s) {
        if (c == '1') cnt1++;
    }

    int i = 0;
    int bestGain = 0;
    int prev = INT_MIN;

    while (i < n) {
        int start = i;

        while (i < n && s[i] == s[start]) {
            i++;
        }

        if (s[start] == '0') {
            int cur = i - start;

            if (prev != INT_MIN) {
                bestGain = max(bestGain, prev + cur);
            }

            prev = cur;
        }
    }

    return cnt1 + bestGain;
}

int main() {
    string s = "1000100";

    cout << maxActiveSectionsAfterTrade(s) << endl;
    cout << maxActiveSectionsAfterTradeI(s) << endl;

    return 0;
}