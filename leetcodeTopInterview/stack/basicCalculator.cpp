#include <bits/stdc++.h>
using namespace std;

int calculate(string s)
{
    stack<int> st;

    int num = 0, res = 0, sign = 1;
    for (int i = 0; i < s.size(); i++)
    {

        char ch = s[i];
        if (isalnum(ch))
        {
            num = num * 10 + (ch - '0');
        }
        else if (ch == '+' || ch == '-')
        {
            res += sign * num;
            num = 0;
            sign = (ch == '+') ? 1 : -1;
        }
        else if (ch == '(')
        {
            st.push(res);
            st.push(sign);
            res = 0;
            sign = 1;
        }
        else if (ch == ')')
        {
            res += sign * num;
            num = 0;
            res *= st.top();
            st.pop();
            res += st.top();
            st.pop();
        }
    }
    res += sign * num;
    return res;
}

int main()
{

    string s = "2-1 + 2";
    cout << calculate(s) << endl;

    return 0;
}