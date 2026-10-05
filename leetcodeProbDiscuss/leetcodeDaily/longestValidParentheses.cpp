#include <bits/stdc++.h>
using namespace std;

// Two pass solution
int longestValidParentheses(string s)
{
    int left = 0;
    int right = 0;
    int maxLength = 0;

    // Pass 1: Left to Right
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            left++;
        }
        else
        {
            right++;
        }

        if (left == right)
        {
            maxLength = max(maxLength, 2 * right);
        }
        else if (right > left)
        {
            left = 0;
            right = 0;
        }
    }

    left = 0;
    right = 0;

    // Pass 2: Right to Left
    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (s[i] == '(')
        {
            left++;
        }
        else
        {
            right++;
        }

        if (left == right)
        {
            maxLength = max(maxLength, 2 * left);
        }
        else if (left > right)
        {
            left = 0;
            right = 0;
        }
    }

    return maxLength;
}

// stack solution
int longestValidParenthesesI(string s)
{
    int maxLength = 0;
    stack<int> st;

    // Push -1 as the initial base index
    st.push(-1);

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            st.push(i);
        }
        else
        {
            st.pop();

            if (st.empty())
            {
                // This closing bracket is invalid; it becomes the new base
                st.push(i);
            }
            else
            {
                // Calculate length using the current index minus the last un-popped character's index
                maxLength = max(maxLength, i - st.top());
            }
        }
    }

    return maxLength;
}

int main()
{
    string s = ")()())";
    cout << longestValidParentheses(s) << endl;
    cout << longestValidParenthesesI(s) << endl;

    return 0;
}