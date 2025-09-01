#include <bits/stdc++.h>
using namespace std;

int getSumOfSquares(int n)
{
    int sum = 0;
    while (n > 0)
    {
        int dig = n % 10;
        sum += dig * dig;
        n /= 10;
    }
    return sum;
}

bool isHappy(int n)
{

    unordered_set<int> st;
    while (n != 1 && (st.find(n) == st.end()))
    {
        st.insert(n);
        n = getSumOfSquares(n);
    }
    return n == 1;
}

int main()
{
    int n = 19;
    cout << isHappy(n) << endl;
    return 0;
}