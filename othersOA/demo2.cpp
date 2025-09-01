#include <bits/stdc++.h>
using namespace std;

string palin(string str)
{
    unordered_map<char, int> mp;
    for (char ch : str)
        mp[ch]++;

    int odd = 0;
    for (auto &i : mp)
    {
        if (i.second % 2 != 0)
            odd++;
    }
    if (odd > 1)
    {
        return "not";
    }
    return "yes";
}

long maxpro(vector<int> &arr)
{
    int n = arr.size();
    if (arr.size() < 4)
        return 0;

    sort(arr.begin(), arr.end());
    long long pro = (int)arr[0] * arr[1] * arr[n - 1] * arr[n - 2];
    return pro;
}

int main()
{

    vector<int> arr = {7, 2, 3, -1, 7, -6, 4, 0};
    cout << maxpro(arr) << endl;

    //     string str = "vicciivv";
    // cout << palin(str) << endl;
    return 0;
}