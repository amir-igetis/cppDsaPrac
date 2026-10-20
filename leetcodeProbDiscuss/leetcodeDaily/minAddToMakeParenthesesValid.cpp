#include <bits/stdc++.h>
using namespace std;

int minAddToMakeValid(string s)
{
    int balance = 0;    // To track the balance of parentheses
    int insertions = 0; // To count the number of insertions needed

    for (char c : s)
    {
        if (c == '(')
        {
            balance++; // Increase balance for an opening parenthesis
        }
        else
        { // c == ')'
            if (balance > 0)
            {
                balance--; // Match with an opening parenthesis
            }
            else
            {
                insertions++; // Need to insert an opening parenthesis
            }
        }
    }

    // Any remaining balance indicates unmatched opening parentheses
    return insertions + balance;
}

int main()
{
    string s = "())";
    int result = minAddToMakeValid(s);
    cout << "Minimum insertions needed to make the parentheses valid: " << result << endl;

    return 0;
}