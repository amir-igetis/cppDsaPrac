#include <bits/stdc++.h>
using namespace std;

// Enumerate the String from Right to Left
// TC: O(n + D * log^2(t))
// SC: O(n)

string smallestNumber(string num, long long t)
{
    long long temp = t;

    // Check whether t can be factorized using digits 2-9
    for (int i = 2; i <= 9; i++)
    {
        while (temp % i == 0)
            temp /= i;
    }

    if (temp > 1)
        return "-1";

    int n = num.length();

    vector<long long> rem(n + 1);
    rem[0] = t;

    int pos = n - 1;

    for (int i = 0; i < n; i++)
    {
        if (num[i] == '0')
        {
            pos = i;
            break;
        }

        rem[i + 1] = rem[i] / __gcd(rem[i], (long long)(num[i] - '0'));
    }

    if (rem[n] == 1)
        return num;

    for (int i = pos; i >= 0; i--)
    {
        while (++num[i] <= '9')
        {
            long long tNow = rem[i] / __gcd(rem[i], (long long)(num[i] - '0'));

            int k = 9;

            for (int j = n - 1; j > i; j--)
            {
                while (k > 1 && tNow % k != 0)
                    k--;

                if (k == 1)
                    break;

                tNow /= k;
                num[j] = char('0' + k);
            }

            if (tNow == 1)
                return num;
        }
    }

    string ans;

    for (int i = 9; i > 1; i--)
    {
        while (t % i == 0)
        {
            ans += char('0' + i);
            t /= i;
        }
    }

    ans += string(max(n + 1 - (int)ans.length(), 0), '1');

    reverse(ans.begin(), ans.end());

    return ans;
}

int main()
{
    string num = "1234";
    long long t = 256;

    cout << smallestNumber(num, t) << endl;

    return 0;
}