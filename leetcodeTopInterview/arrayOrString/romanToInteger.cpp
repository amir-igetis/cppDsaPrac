#include <bits/stdc++.h>
using namespace std;

int romanToInt(string s)
{
    if (s.size() == 0)
        return 0;

    unordered_map<char, int> val = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}};
    int total = 0;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        int curr = val[s[i]];
        int next = (i + 1 < n) ? val[s[i + 1]] : 0;

        if (curr < next)
            total -= curr;
        else
            total += curr;
    }
    return total;
}

int main()
{

    string s = "LVIII";
    cout << romanToInt(s) << endl;

    return 0;
}