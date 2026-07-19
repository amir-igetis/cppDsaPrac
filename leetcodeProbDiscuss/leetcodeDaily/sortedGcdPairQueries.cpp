#include <bits/stdc++.h>
using namespace std;

vector<int> gcdValues(vector<int> &nums, vector<long long> &queries)
{
    int m = 0;
    for (int num : nums)
    {
        m = max(m, num);
    }
    vector<long long> cnt(m + 1);
    for (int num : nums)
    {
        cnt[num]++;
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = i * 2; j <= m; j += i)
        {
            cnt[i] += cnt[j];
        }
    }
    for (int i = 1; i <= m; i++)
    {
        cnt[i] = (cnt[i] * (cnt[i] - 1)) / 2;
    }
    for (int i = m; i >= 1; i--)
    {
        for (int j = i * 2; j <= m; j += i)
        {
            cnt[i] -= cnt[j];
        }
    }
    for (int i = 1; i <= m; i++)
    {
        cnt[i] += cnt[i - 1];
    }
    vector<int> ans(queries.size());
    for (int k = 0; k < queries.size(); k++)
    {
        long q = queries[k] + 1;
        int left = 1,
            right = m;
        while (left < right)
        {
            int mid = (left + right) / 2;
            if (cnt[mid] >= q)
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        ans[k] = left;
    }
    return ans;
}

int main()
{

    vector<int> nums = {2, 3, 4};
    vector<long long> queries = {0, 2, 2};
    vector<int> ans = gcdValues(nums, queries);
    for (int i = 0; i < ans.size(); i++)
    {

        cout << ans[i] << " ";
    }

    return 0;
}