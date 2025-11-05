#include <bits/stdc++.h>
using namespace std;

vector<int> findXSum(vector<int> &nums, int k, int x)
{
    int n = nums.size();
    vector<int> ans;

    for (int i = 0; i + k <= n; i++)
    {
        unordered_map<int, int> freq;

        for (int j = i; j < i + k; j++)
            freq[nums[j]]++;

        vector<pair<int, int>> freqList(freq.begin(), freq.end());

        sort(freqList.begin(), freqList.end(), [](auto &a, auto &b)
             {
            if (a.second== b.second)
            return a.first > b.first;
            return a.second > b.second; });

        unordered_set<int> topElements;
        for (int j = 0; j < min(x, (int)freqList.size()); j++)
            topElements.insert(freqList[j].first);

        int sum = 0;
        for (int j = i; j < i + k; j++)
            if (topElements.count(nums[j]))
                sum += nums[j];

        ans.push_back(sum);
    }

    return ans;
}

int main()
{

    vector<int> nums = {1, 1, 2, 2, 3, 4, 2, 3};
    int k = 6, x = 2;
    vector<int> ans = findXSum(nums, k, x);

    for (int i : ans)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}