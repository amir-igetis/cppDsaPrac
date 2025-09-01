#include <bits/stdc++.h>
using namespace std;

string convert(string s, int numRows)
{
    if (numRows == 1 || numRows >= s.length())
        return s;

    vector<string> str(min(numRows, int(s.length())));

    int currRow = 0;
    bool goingDown = false;

    for (char c : s)
    {
        str[currRow] += c;

        if (currRow == 0 || currRow == numRows - 1)
            goingDown = !goingDown;

        currRow += goingDown ? 1 : -1;
    }

    string res;
    for (string i : str)
        res += i;

    return res;
}

int main()
{

    string s = "PAYPALISHIRING";
    int numRows = 3;

    cout << convert(s, numRows) << endl;

    return 0;
}