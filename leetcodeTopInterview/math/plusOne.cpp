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

int main()
{

    vector<int> digits = {4, 3, 2, 1};
    vector<int> ans = plusOne(digits);
    for (int i : ans)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}