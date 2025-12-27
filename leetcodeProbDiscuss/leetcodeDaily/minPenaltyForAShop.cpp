#include <bits/stdc++.h>
using namespace std;

// one pass
int bestClosingTime(string customers)
{
    int earliestHour = 0;
    int penalty = 0;
    int minPenalty = 0;
    for (int i = 0; i < customers.length(); i++)
    {
        char ch = customers[i];
        if (ch == 'Y')
            penalty--;
        else
            penalty++;

        if (penalty < minPenalty)
        {
            earliestHour = i + 1;
            minPenalty = penalty;
        }
    }
    return earliestHour;
}

// two passes
int bestClosingTimeI(string customers)
{
    int currPenalty = 0;
    for (int i = 0; i < customers.size(); i++)
        if (customers[i] == 'Y')
            currPenalty++;

    int minPenalty = currPenalty;
    int earliestHour = 0;
    for (int i = 0; i < customers.size(); i++)
    {
        char ch = customers[i];
        if (ch == 'Y')
            currPenalty--;
        else
            currPenalty++;

        if (currPenalty < minPenalty)
        {
            earliestHour = i + 1;
            minPenalty = currPenalty;
        }
    }

    return earliestHour;
}

int main()
{

    string customers = "YYNY";
    cout << bestClosingTime(customers) << endl;

    return 0;
}