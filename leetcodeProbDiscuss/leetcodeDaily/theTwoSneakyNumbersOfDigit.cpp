#include <bits/stdc++.h>
using namespace std;

vector<int> getSneakyNumbers(vector<int> &nums)
{
    unordered_set<int> seen;
    vector<int> duplicates;

    for (auto &i : nums)
    {
        if (seen.count(i))
            duplicates.push_back(i);
        else
            seen.insert(i);
    }

    return {duplicates[0], duplicates[1]};
}

vector<int> getSneakyNumbersI(vector<int> &nums)
{
    int n = nums.size();
    vector<int> count(n);
    vector<int> res(2);
    int idx = 0;

    for (auto &i : nums)
    {
        count[i]++;
        if (count[i] == 2)
            res[idx++] = i;
    }
    return res;
}

int main()
{

    vector<int> nums = {0, 3, 2, 1, 3, 2};
    vector<int> ans = getSneakyNumbersI(nums);
    for (auto &i : ans)
        cout << i << " ";
    cout << endl;

    return 0;
}