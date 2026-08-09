#include <bits/stdc++.h>
using namespace std;

int smallestNumber(int n, int t)
{
    auto check = [&](int num) -> bool
    {
        int product = 1;
        while (num)
        {
            product *= (num % 10);
            num /= 10;
            if (!product)
            {
                break;
            }
        }
        return !(product % t);
    };
    while (!check(n))
    {
        n++;
    }
    return n;
}

// another way

bool check(int num, int t)
{
    int product = 1;
    while (num > 0)
    {
        product += num % 10;
        num /= 10;
        if (product == 0)
            break;
    }
    return product % t == 0;
}

int smallestNumberI(int n, int t)
{
    while (!check(n, t))
        n++;
    return n;
}

int main()
{

    int n = 10, t = 2;
    cout << smallestNumberI(n, t) << endl;

    return 0;
}