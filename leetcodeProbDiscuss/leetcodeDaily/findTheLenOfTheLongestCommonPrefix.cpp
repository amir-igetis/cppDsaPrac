#include <bits/stdc++.h>
using namespace std;

int longestCommonPrefix(vector<int> &arr1, vector<int> &arr2)
{
    unordered_set<string> prefixes;

    // Store all prefixes of numbers in arr1
    for (int num : arr1)
    {
        string s = to_string(num);
        string pref = "";

        for (char ch : s)
        {
            pref += ch;
            prefixes.insert(pref);
        }
    }

    int ans = 0;

    // Check prefixes of numbers in arr2
    for (int num : arr2)
    {
        string s = to_string(num);
        string pref = "";

        for (char ch : s)
        {
            pref += ch;

            if (prefixes.count(pref))
            {
                ans = max(ans, (int)pref.size());
            }
        }
    }

    return ans;
}

int main()
{
    vector<int> arr1 = {1, 2, 3}, arr2 = {4, 4, 4};
    cout << longestCommonPrefix(arr1, arr2) << endl;

    return 0;
}