#include <bits/stdc++.h>
using namespace std;

int isValid(string s)
{
    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            st.push(s[i]);
        else
        {
            if (st.size() == 0)
                return false;
            char ch = st.top();
            st.pop();
            if ((s[i] == ')' and ch == '(') or (s[i] == '}' and ch == '{') or (s[i] == ']' and ch == '['))
                continue;
            else
                return false;
        }
    }
    return st.empty();
}

int main()
{
    string s = "()[{}()]";
    if (isValid(s))
        cout << "True" << endl;
    else
        cout << "False" << endl;
    return 0;
}