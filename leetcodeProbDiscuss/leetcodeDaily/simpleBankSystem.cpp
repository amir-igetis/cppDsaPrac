#include <bits/stdc++.h>
using namespace std;

class Bank
{

private:
    vector<long long> balance;
    int n;

public:
    Bank(vector<long long> &balance)
    {
        this->balance = balance;
        this->n = balance.size();
    }

    bool transfer(int account1, int account2, long long money)
    {
        if (account1 < 1 || account1 > n)
            return false;

        if (account2 < 1 || account2 > n)
            return false;

        if (balance[account1 - 1] < money)
            return false;

        balance[account1 - 1] -= money;
        balance[account2 - 1] += money;

        return true;
    }

    bool deposit(int account, long long money)
    {
        if (account < 1 || account > n)
            return false;

        balance[account - 1] += money;
        return true;
    }

    bool withdraw(int account, long long money)
    {
        if (account < 1 || account > n)
            return false;

        if (balance[account - 1] < money)
            return false;

        balance[account - 1] -= money;
        return true;
    }
};

int main()
{

    vector<long long> balance = {10, 100, 20, 50, 30};
    Bank obj(balance);

    cout << (obj.withdraw(3, 10) ? "True" : "False") << endl;
    cout << (obj.transfer(5, 1, 20) ? "True" : "False") << endl;
    cout << (obj.deposit(5, 20) ? "True" : "False") << endl;
    cout << (obj.transfer(3, 4, 15) ? "True" : "False") << endl;
    cout << (obj.withdraw(10, 50) ? "True" : "False") << endl;

    return 0;
}