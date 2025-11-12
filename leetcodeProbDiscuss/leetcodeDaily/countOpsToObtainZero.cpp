#include <bits/stdc++.h>
using namespace std;

int countOperations(int num1, int num2)
{
    int count = 0;
    while (num1 != 0 && num2 != 0)
    {
        if (num1 >= num2)
            num1 -= num2;
        else
            num2 -= num1;

        count++;
    }

    return count;
}

int countOperationsI(int num1, int num2)
{
    int count = 0;
    while (num1 != 0 && num2 != 0)
    {
        if (num1 >= num2)
        {
            count += num1 / num2;
            num1 %= num2;
        }
        else
        {
            count += num2 / num1;
            num2 %= num1;
        }
    }
    return count;
}

int main()
{
    int num1 = 2, num2 = 3;
    cout << countOperationsI(num1, num2) << endl;

    return 0;
}