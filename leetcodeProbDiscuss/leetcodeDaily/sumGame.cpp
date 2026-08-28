#include <bits/stdc++.h>
using namespace std;

// Guess + Mathematical Induction Verification

/// Let n be the length of the string num.
///
/// Time complexity: O(n).
///
/// Space complexity: O(n).

bool sumGame(string num)
{
    int n = num.size();

    auto get = [](string &&s) -> pair<int, int>
    {
        int nn = 0, qq = 0;

        for (char ch : s)
        {
            if (ch == '?')
            {
                ++qq;
            }
            else
            {
                nn += (ch - '0');
            }
        }

        return {nn, qq};
    };

    pair<int, int> left = get(num.substr(0, n / 2));
    pair<int, int> right = get(num.substr(n / 2, n / 2));

    int n0 = left.first;
    int q0 = left.second;

    int n1 = right.first;
    int q1 = right.second;

    return ((q0 + q1) % 2 == 1) ||
           (n0 - n1 != (q1 - q0) * 9 / 2);
}

int main()
{
    string num = "?3295???";
    cout << sumGame(num) << endl;

    return 0;
}