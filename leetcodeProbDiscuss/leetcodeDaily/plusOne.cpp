#include <bits/stdc++.h>
using namespace std;

vector<int> plusOne(vector<int> &digits)
{
    int n = digits.size();
    for (int i = n - 1; i >= 0; i--)
    {
        if (digits[i] < 9)
        {
            digits[i]++;
            return digits;
        }
        digits[i] = 0;
    }
    vector<int> res(n + 1);
    res[0] = 1;
    return res;
}

// soln from leetcode
vector<int> plusOneI(vector<int> &digits)
{
    int carry = 1;
    for (int i = digits.size() - 1; i >= 0; i--)
    {
        int sum = digits[i] + carry;
        digits[i] = sum % 10;
        carry = sum / 10;
    }
    if (carry)
    {
        digits.insert(digits.begin(), 1);
    }
    return digits;
}

int main()
{
    vector<int> digits = {1, 2, 3};
    vector<int> res = plusOneI(digits);
    for (auto &i : res)
        cout << i << " ";
    cout << endl;

    return 0;
}