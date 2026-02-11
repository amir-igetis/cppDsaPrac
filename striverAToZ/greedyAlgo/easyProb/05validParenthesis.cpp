#include <bits/stdc++.h>
using namespace std;

//  tc O(n) & sc O(1)
bool isValid(string s)
{
    int minOpen = 0, maxOpen = 0;
    for (char ch : s)
    {
        if (ch == '(')
        {
            minOpen++;
            maxOpen++;
        }
        else if (ch == ')')
        {
            minOpen--;
            maxOpen--;
        }
        else
        {
            minOpen--;
            maxOpen++;
        }
        if (maxOpen < 0)
            return false;
        minOpen = max(minOpen, 0);
    }
    return minOpen == 0;
}

int main()
{

    string s = "(({})";
    cout << (isValid(s) ? "True" : "False") << endl;

    return 0;
}