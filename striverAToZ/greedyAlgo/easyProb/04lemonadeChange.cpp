#include <bits/stdc++.h>
using namespace std;

// greedy tc O(n)  & sc O(1)
bool lemonadeChange(vector<int> &bills)
{
    int five = 0;
    int ten = 0;
    for (int i : bills)
    {
        if (i == 5)
        {
            five++;
        }
        else if (i == 10)
        {
            if (five > 0)
            {
                five--;
                ten++;
            }
            else
            {
                return false;
            }
        }
        else
        {
            if (five > 0 && ten > 0)
            {
                five--;
                ten--;
            }
            else if (five >= 3)
            {
                five -= 3;
            }
            else
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{

    vector<int> bills = {5, 5, 5, 10, 20};
    cout << (lemonadeChange(bills) ? "True" : "False") << endl;

    return 0;
}