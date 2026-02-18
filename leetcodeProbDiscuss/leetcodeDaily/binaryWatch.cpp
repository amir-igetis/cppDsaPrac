#include <bits/stdc++.h>
using namespace std;

vector<string> readBinaryWatch(int turnedOn)
{
    vector<string> times;
    for (int h = 0; h < 12; h++)
    {
        for (int m = 0; m < 60; m++)
        {
            if (__builtin_popcount(h * 64 + m) == turnedOn)
            {
                string time = to_string(h) + ":" +
                              (m < 10 ? "0" : "") + to_string(m);
                times.push_back(time);
            }
        }
    }
    return times;
}

vector<string> readBinaryWatchI(int num)
{
    vector<string> res;

    // iterate through all possible times
    for (int h = 0; h < 12; h++)
        for (int m = 0; m < 60; m++)
            // Now store the time in bitset of size 10
            // where first 4 digits represent hours and
            // last 6 digits represent minutes, that's why
            // hours is left shifted 6 bits. If the count of
            // set bits equals num then append this time in our result
            if (bitset<10>(h << 6 | m).count() == num)
                // if minutes is single digit append 0 in front of it
                res.emplace_back(to_string(h) + (m < 10 ? ":0" : ":") + to_string(m));

    return res;
}

int main()
{

    int turnedOn = 1;
    vector<string> ans = readBinaryWatchI(turnedOn);
    for (auto &i : ans)
        cout << i << " ";
    cout << endl;

    return 0;
}