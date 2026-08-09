#include <bits/stdc++.h>
using namespace std;

vector<int> findMissingElements(vector<int> &nums)
{
    vector<int> ans;
    int n = nums.size();
    vector<int> hash(101, 0);
    int maxi = 0;
    int mini = 101;
    for (int i = 0; i < n; i++)
    {
        int node = nums[i];
        hash[node]++;
        maxi = max(maxi, nums[i]);
        mini = min(mini, nums[i]);
    }
    for (int i = mini; i < maxi; i++)
        if (hash[i] == 0)
            ans.push_back(i);

    return ans;
}

vector<int> findMissingElementsI(vector<int> &nums)
{
    int mn = *min_element(nums.begin(), nums.end());
    int mx = *max_element(nums.begin(), nums.end());

    unordered_set<int> st(nums.begin(), nums.end());

    vector<int> ans;

    for (int i = mn; i <= mx; i++)
    {
        if (st.count(i) == 0)
            ans.push_back(i);
    }

    return ans;
}

int main()
{

    vector<int> nums = {1, 4, 2, 5};
    // vector<int> nums = {7, 8, 6, 9};
    vector<int> ans = findMissingElementsI(nums);
    for (auto &i : ans)
        cout << i << " ";
    cout << endl;

    return 0;
}