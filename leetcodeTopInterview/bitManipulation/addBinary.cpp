#include <bits/stdc++.h>
using namespace std;

string addBinary(string a, string b)
{
    string res;
    int carry = 0;
    int i = a.size() - 1, j = b.size() - 1;

    while (i >= 0 || j >= 0 || carry > 0)
    {
        int sum = carry;
        if (i >= 0)
            sum += a[i--] - '0';
        if (j >= 0)
            sum += b[j--] - '0';

        res.push_back((sum % 2) + '0'); // append '0' or '1'
        carry = sum / 2;
    }

    reverse(res.begin(), res.end());
    return res;
}

string addBinaryI(string a, string b)
{
    // Convert binary strings to integers using bitset
    bitset<1024> x(a); // supports up to 1024 bits
    bitset<1024> y(b);

    auto sum = x.to_ullong() + y.to_ullong(); // works if sum fits in unsigned long long
    bitset<1024> res(sum);

    string result = res.to_string();
    // trim leading zeros
    return result.substr(result.find('1'));
}

// Function to add two integers using bit manipulation
unsigned long long addUnsigned(unsigned long long x, unsigned long long y)
{
    while (y != 0)
    {
        unsigned long long carry = (x & y) << 1; // carry
        x = x ^ y;                               // sum without carry
        y = carry;                               // update carry
    }
    return x;
}

string addBinaryII(string a, string b)
{
    unsigned long long x = stoull(a, nullptr, 2); // convert binary -> int
    unsigned long long y = stoull(b, nullptr, 2);

    unsigned long long sum = addUnsigned(x, y);

    // convert back to binary string
    string res = bitset<128>(sum).to_string();
    return res.substr(res.find('1')); // trim leading zeros
}

int main()
{
    string a = "1010", b = "1011";
    cout << addBinary(a, b) << endl; // Output: "10101"
    return 0;
}
