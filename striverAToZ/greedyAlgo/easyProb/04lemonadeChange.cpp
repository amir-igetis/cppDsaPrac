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

/// You are selling lemonade at a stand where each glass costs exactly $5. 
/// Customers are standing in a queue to buy from you, and order one at a time. 
/// Each customer will only buy one lemonade and pay with either a $5, $10, or $20 bill.
/// 
/// You must provide the correct change to each customer so that the net transaction 
/// is exactly $5. You start with no money in your cash register. Return true if you 
/// can provide every customer with correct change, or false if you cannot.
int main()
{

    vector<int> bills = {5, 5, 5, 10, 20};
    cout << (lemonadeChange(bills) ? "True" : "False") << endl;

    return 0;
}