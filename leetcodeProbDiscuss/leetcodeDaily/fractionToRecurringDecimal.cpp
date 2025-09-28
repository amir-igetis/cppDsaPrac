

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// another way
// #define ll long long

string fractionToDecimal(int numerator, int denominator)
{
    if (numerator == 0)
        return "0";

    string res;
    if ((numerator < 0) ^ (denominator < 0))
        res += "-";

    ll n = llabs((ll)numerator);
    ll d = llabs((ll)denominator);

    res += to_string(n / d);
    ll remainder = n % d;

    if (remainder == 0)
        return res;

    res += ".";

    unordered_map<ll, int> seen;

    while (remainder != 0)
    {
        if (seen.count(remainder))
        {
            res.insert(seen[remainder], "(");
            res += ")";
            break;
        }
        seen[remainder] = res.size();
        remainder *= 10;
        res += to_string(remainder / d);
        remainder %= d;
    }
    return res;
}

int main()
{

    cout << fractionToDecimal(1, 2) << endl;   // "0.5"
    cout << fractionToDecimal(2, 1) << endl;   // "2"
    cout << fractionToDecimal(2, 3) << endl;   // "0.(6)"
    cout << fractionToDecimal(-50, 8) << endl; // "-6.25"
    cout << fractionToDecimal(1, 6) << endl;   // "0.1(6)"

    return 0;
}