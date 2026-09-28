#include <bits/stdc++.h>
using namespace std;

// Stack

/// Here, N is the number of characters in the string s.
///
/// Time complexity: O(N)
///
/// We are iterating over each character in the string s, and hence the time complexity will be equal to O(N).
///
/// Space complexity: O(N)
///
/// The size of the stack can grow up to n/2
///   for strings like (((()))), and hence the space complexity of this approach will be O(N).
int maxDepth(string s)
{
    int ans = 0;

    stack<char> st;
    for (char c : s)
    {
        if (c == '(')
        {
            st.push(c);
        }
        else if (c == ')')
        {
            st.pop();
        }

        ans = max(ans, (int)st.size());
    }

    return ans;
}

// Counter Variable

/// Complexity Analysis
/// Here, N is the number of characters in the string s.
///
/// Time complexity: O(N)
///
/// We are iterating over each character in the string s, and hence the time complexity will be equal to O(N).
///
/// Space complexity: O(1)
///
/// The only variables we require are openBrackets and ans. Hence, the space complexity is constant.
int maxDepthI(string s)
{
    int ans = 0;
    int openBrackets = 0;

    for (char c : s)
    {
        if (c == '(')
        {
            openBrackets++;
        }
        else if (c == ')')
        {
            openBrackets--;
        }

        ans = max(ans, openBrackets);
    }

    return ans;
}

int main()
{
    string s = "(1+(2*3)+((8)/4))+1";
    cout << maxDepth(s) << endl;
    cout << maxDepthI(s) << endl;

    return 0;
}