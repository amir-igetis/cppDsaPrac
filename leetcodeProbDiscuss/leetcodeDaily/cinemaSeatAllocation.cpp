#include <bits/stdc++.h>
using namespace std;

// bitwise Operations
/// Let r be the length of the array reservedSeats.
///
/// Time complexity: O(r).
///
/// We first traverse reservedSeats to record the reservation information in the hash map, and then traverse the hash map to compute the answer. Both operations take O(r) time in total.
///
/// Space complexity: O(r).
///
/// The hash map stores the reservation information for each row that has at least one reserved seat among positions 2 to 9. In the worst case, it can contain O(r) entries.

int maxNumberOfFamilies(int n, vector<vector<int>> &reservedSeats)
{
    int left = 0b11110000;
    int middle = 0b11000011;
    int right = 0b00001111;

    unordered_map<int, int> occupied;
    for (const vector<int> &seat : reservedSeats)
    {
        if (seat[1] >= 2 && seat[1] <= 9)
        {
            occupied[seat[0]] |= (1 << (seat[1] - 2));
        }
    }

    int ans = (n - occupied.size()) * 2;
    // for (auto& [row, bitmask] : occupied) {
    //     if (((bitmask | left) == left) || ((bitmask | middle) == middle) ||
    //         ((bitmask | right) == right)) {
    //         ++ans;
    //     }
    // }

    for (auto it = occupied.begin(); it != occupied.end(); ++it)
    {
        int row = it->first;
        int bitmask = it->second;

        if (((bitmask | left) == left) ||
            ((bitmask | middle) == middle) ||
            ((bitmask | right) == right))
        {
            ++ans;
        }
    }

    return ans;
}

int main()
{
    vector<vector<int>> reservedSeats = {{2, 1}, {1, 8}, {2, 6}};
    int n = 2;
    cout << maxNumberOfFamilies(n, reservedSeats) << endl; // Output: 2

    return 0;
}
