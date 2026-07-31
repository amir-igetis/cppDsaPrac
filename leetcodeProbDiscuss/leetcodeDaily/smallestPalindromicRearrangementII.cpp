#include <bits/stdc++.h>
using namespace std;

/* Time complexity: O(n⋅σ⋅(σ+min(n,logk))).

For each position in the left half, we enumerate all candidate characters, which costs O(σ). For every candidate, computing the number of remaining permutations takes O(σ+min(n,logk)). Therefore, the total time complexity is
O(n⋅σ⋅(σ+min(n,logk))).
The analysis of the permutation-counting procedure is given above.

Space complexity: O(1) or O(n).

The frequency array bucket occupies O(σ) space, which is constant. The overall space complexity depends on whether the palindrome is constructed in place or by creating additional strings.
*/

long long comb(long long n, long long m, long long k)
{
    long long res = 1;
    m = min(m, n - m);

    for (long long i = 1; i <= m; i++)
    {
        res = res * (n - i + 1) / i;
        if (res > k)
        {
            return k + 1;
        }
    }
    return res;
}

string smallestPalindrome(string s, long long k)
{
    int partition = s.length() / 2;
    vector<int> bucket(26, 0);

    for (int i = 0; i < partition; i++)
    {
        bucket[s[i] - 'a'] += 1;
    }

    auto permutations = [&](int rem)
    {
        long long ways = 1;
        for (int i = 0; i < 26; i++)
        {
            if (bucket[i] == 0)
            {
                continue;
            }

            ways *= comb(rem, bucket[i], k);
            if (ways > k)
            {
                break;
            }
            rem -= bucket[i];
        }
        return ways;
    };

    string left = "";
    long long startIndex = 1;

    for (int pos = 0; pos < partition; pos++)
    {
        for (int i = 0; i < 26; i++)
        {
            if (bucket[i] == 0)
            {
                continue;
            }

            bucket[i] -= 1;

            long long ways = permutations(partition - pos - 1);
            if (startIndex + ways > k)
            {
                left += (char)(i + 'a');
                break;
            }

            bucket[i] += 1;
            startIndex += ways;
        }
    }

    if (left.length() < partition)
    {
        return "";
    }

    string mid =
        s.length() % 2 != 0 ? string(1, s[partition]) : "";
    string right = left;
    reverse(right.begin(), right.end());

    return left + mid + right;
}

int main()
{
    string s = "aabbcc";
    long long k = 3;

    cout << smallestPalindrome(s, k) << endl;

    return 0;
}
