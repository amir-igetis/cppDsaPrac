#include <bits/stdc++.h>
using namespace std;

int finalValueAfterOperations(vector<string> &operations)
{
    int x = 0;
    for (auto &i : operations)
    {
        if (i == "X++" || i == "++X")
            x += 1;
        else
            x -= 1;
    }
    return x;
}

// another way
int finalValueAfterOperationsI(vector<string> &operations)
{
    int x = 0;
    for (int i = 0; i < operations.size(); i++)
    {
        if (operations[i] == "X++" || operations[i] == "++X")
            x += 1;
        else
            x -= 1;
    }
    return x;
}

int main()
{

    vector<string> operations = {"--X", "X++", "X++"};
    cout << finalValueAfterOperationsI(operations) << endl;

    return 0;
}