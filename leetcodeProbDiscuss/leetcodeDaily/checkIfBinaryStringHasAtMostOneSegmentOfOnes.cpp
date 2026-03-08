#include <bits/stdc++.h>
using namespace std;

bool checkOnesSegment(string s)
{
    return string::npos == s.find("01");
}

int main()
{
    string s = "1001";
    cout << (checkOnesSegment(s) ? "True" : "False") << endl;
    return 0;
}