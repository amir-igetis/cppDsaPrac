#include <bits/stdc++.h>
using namespace std;

string removeKDig(string num, int k)
{
    stack<char> st;

    for (char dig : num)
    {
        while (!st.empty() && k > 0 && st.top() > dig)
        {
            st.pop();
            k--;
        }
        st.push(dig);
    }

    while (k > 0 && !st.empty())
    {
        st.pop();
        k--;
    }

    string res = "";
    while (!st.empty())
    {
        res = st.top() + res;
        st.pop();
    }

    int i = 0;
    while (i < res.size() && res[i] == '0')
        i++;
    res = res.substr(i);

    return res.empty() ? "0" : res;
}

int main()
{

    string num = "1432219";
    int k = 3;
    cout << removeKDig(num, k) << endl;
    return 0;
}