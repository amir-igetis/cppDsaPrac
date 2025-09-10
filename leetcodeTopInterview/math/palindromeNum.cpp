#include <bits/stdc++.h>
using namespace std;

void isPalindrome(int x)
{
    int n = x;
    int num;
    while (n != 0)
    {
        int rem = n % 10;
        num = num * 10 + rem;
        // it will be

        n /= 10;
    }
    cout << num;
    if (x == num)
        cout << " true";
    else
        cout << "false";
}

bool isPalindromeI(int x)
{
    if (x < 0)
        return false; // negative numbers are not palindrome

    int num = x;
    long long rev = 0; // use long long to prevent overflow

    while (num != 0)
    {
        int rem = num % 10;
        rev = rev * 10 + rem; // build reversed number
        num /= 10;
    }

    return x == rev;
}

int main()
{

    int n = 121;
    isPalindrome(n);
    cout << (isPalindromeI(n) ? "True" : "False") << endl;
    return 0;
}