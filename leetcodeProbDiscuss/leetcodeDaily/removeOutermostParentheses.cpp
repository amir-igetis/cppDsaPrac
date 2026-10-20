#include <bits/stdc++.h>
using namespace std;

// stack

/// Let n be the length of the input s.
///
/// Time complexity: O(n).
///
/// We only need to traverse s once.
///
/// Space complexity: O(n).
///
/// The stack stores at most n/2 characters in the worst case (e.g., when all opening parentheses are nested), taking O(n) auxiliary space.

string removeOuterParentheses(string s)
{
    string res;
    stack<char> st;
    for (auto c : s)
    {
        if (c == ')')
        {
            st.pop();
        }
        if (!st.empty())
        {
            res.push_back(c);
        }
        if (c == '(')
        {
            st.emplace(c);
        }
    }
    return res;
}

// counting

/// Let n be the length of the input s.
///
/// Time complexity: O(n).
///
/// We only need to traverse s once.
///
/// Space complexity: O(1).
///
/// Excluding the space required to store the output string, only a constant amount of extra space is used for variables.
string removeOuterParenthesesI(string s)
{
    int level = 0;
    string res;
    for (auto c : s)
    {
        if (c == ')')
        {
            level--;
        }
        if (level)
        {
            res.push_back(c);
        }
        if (c == '(')
        {
            level++;
        }
    }
    return res;
}

int main()
{
    string s = "(()())(())";
    cout << removeOuterParentheses(s) << endl;
    cout << removeOuterParenthesesI(s) << endl;

    return 0;
}
