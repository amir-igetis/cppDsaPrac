#include <bits/stdc++.h>
using namespace std;

bool hasAllCodes(string s, int k)
{
    if (k > s.size())
        return false;
    unordered_set<string> st;
    for (int i = 0; i <= s.size() - k; i++)
        st.insert(s.substr(i, k));
    return st.size() == (1 << k);
}

int main()
{

    string s = "00110110";
    int k = 2;
    cout << (hasAllCodes(s, k) ? "True" : "False") << endl;

    return 0;
}