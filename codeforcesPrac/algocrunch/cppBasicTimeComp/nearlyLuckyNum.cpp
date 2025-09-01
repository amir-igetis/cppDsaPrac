#include <bits/stdc++.h>
using namespace std;

string func(long long n)
{
    int count = 0;
    while (n != 0)
    {
        if (n % 10 == 4 || n % 10 == 7)
        {
            count += 1;
        }
        n /= 10;
    }
    if (count == 4 || count == 7)
    {
        return "YES";
    }
    return "NO";
}

int main()
{
    long long n;
    cin >> n;
    string res = func(n);

    cout << res << endl;

    return 0;
}