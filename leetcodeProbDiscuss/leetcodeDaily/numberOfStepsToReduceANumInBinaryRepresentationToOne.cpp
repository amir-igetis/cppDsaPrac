#include <bits/stdc++.h>
using namespace std;

int numSteps(string s)
{
    int res = 0;
    int carry = 0;
    for (int i = s.size() - 1; i > 0; i--)
    {
        res++;
        if (s[i] - '0' + carry == 1)
        {
            carry = 1;
            res++;
        }
    }
    return carry + res;
}

int main()
{

    string s = "1101";
    cout << numSteps(s) << endl;
    return 0;
}