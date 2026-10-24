#include <bits/stdc++.h>
using namespace std;

// Convert Dates to Days of the Year and Calculate the Difference

/// Time complexity: O(1).
///
/// Computing the prefix sums takes constant time since there are only 12 months in a year. Parsing the four fixed-length date strings (5 characters each) and finding the overlap also takes constant time. Thus, the total time complexity is O(1).
///
/// Space complexity: O(1).
///
/// The array storing the number of days in each month and its prefix sum array require fixed sizes of 12 and 13, so the space complexity is constant
int calculateDayOfYear(const string &day, const vector<int> &prefixSum)
{
    int month = stoi(day.substr(0, 2));
    int date = stoi(day.substr(3));
    return prefixSum[month - 1] + date;
}

int countDaysTogether(string arriveAlice, string leaveAlice,
                      string arriveBob, string leaveBob)
{
    vector<int> datesOfMonths = {31, 28, 31, 30, 31, 30,
                                 31, 31, 30, 31, 30, 31};
    vector<int> prefixSum(1, 0);
    for (int date : datesOfMonths)
    {
        prefixSum.emplace_back(prefixSum.back() + date);
    }

    int arriveAliceDay = calculateDayOfYear(arriveAlice, prefixSum);
    int leaveAliceDay = calculateDayOfYear(leaveAlice, prefixSum);
    int arriveBobDay = calculateDayOfYear(arriveBob, prefixSum);
    int leaveBobDay = calculateDayOfYear(leaveBob, prefixSum);
    return max(0, min(leaveAliceDay, leaveBobDay) -
                      max(arriveAliceDay, arriveBobDay) + 1);
}

int main()
{
    string arriveAlice = "08-15", leaveAlice = "08-18", arriveBob = "08-16", leaveBob = "08-19";
    cout << countDaysTogether(arriveAlice, leaveAlice, arriveBob, leaveBob) << endl;

    return 0;
}