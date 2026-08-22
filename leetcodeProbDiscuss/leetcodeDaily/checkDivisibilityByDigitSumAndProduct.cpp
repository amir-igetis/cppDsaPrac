#include <bits/stdc++.h>
using namespace std;

int getSum(int n)
{
    int sum = 0;
    while (n > 0)
    {
        int rem = n % 10;
        sum += rem;
        n /= 10;
    }
    return sum;
}

int getProd(int n)
{
    int prod = 1;
    while (n > 0)
    {
        int rem = n % 10;
        prod *= rem;
        n /= 10;
    }
    return prod;
}

bool checkDivisibility(int n)
{

    int sum = getSum(n);
    int prod = getProd(n);
    return n % (sum + prod) == 0 ? true : false;
}

// another way single pass
bool checkDivisibilityI(int n)
{

    int s = 0, p = 1;
    for (int i = n; i > 0; i /= 10)
    {
        int rem = i % 10;
        s += rem;
        p *= rem;
    }
    return n % (s + p) == 0 ? true : false;
}

int main()
{

    int n = 99;
    cout << (checkDivisibility(n) ? "True" : "False") << endl;
    cout << (checkDivisibilityI(n) ? "True" : "False") << endl;
    cout << getSum(n) << endl;
    cout << getProd(n) << endl;
}
