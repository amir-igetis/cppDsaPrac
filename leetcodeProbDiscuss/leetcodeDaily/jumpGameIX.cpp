#include <bits/stdc++.h>
using namespace std;

// Interval Divide and Conquer
vector<int> maxValue(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans(n, 0);

    // [value, index]
    using Item = pair<int, int>;
    vector<Item> prevMax(n);

    Item prev = {INT_MIN, -1};

    for (int i = 0; i < n; ++i)
    {
        if (nums[i] > prev.first)
        {
            prev = {nums[i], i};
        }

        prevMax[i] = prev;
    }

    auto process = [&](auto &self, int r, int rightMin,
                       int rightMax) -> void
    {
        int pMax = prevMax[r].first;
        int pivotIndex = prevMax[r].second;

        int currMax = pMax <= rightMin ? pMax : rightMax;

        int nextRightMin = min(pMax, rightMin);

        for (int i = pivotIndex; i <= r; ++i)
        {
            ans[i] = currMax;
            nextRightMin = min(nextRightMin, nums[i]);
        }

        if (pivotIndex == 0)
        {
            return;
        }

        self(self, pivotIndex - 1, nextRightMin, currMax);
    };

    process(process, n - 1, INT_MAX, 0);

    return ans;
}

struct Item
{
    int value;
    int left;
    int right;
};

// Monotonic Stack

vector<int> maxValueI(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans(n, 0);

    vector<Item> stack;

    for (int i = 0; i < n; ++i)
    {
        Item curr = {nums[i], i, i};

        while (!stack.empty() && stack.back().value > nums[i])
        {
            Item top = stack.back();
            stack.pop_back();
            curr.value = max(curr.value, top.value);
            curr.left = top.left;
        }

        stack.push_back(curr);
    }

    for (size_t i = 0; i < stack.size(); ++i)
    {
        for (int j = stack[i].left; j <= stack[i].right; ++j)
        {
            ans[j] = stack[i].value;
        }
    }

    return ans;
}

vector<int> maxValueII(vector<int> &a)
{
    int n = a.size();
    vector<int> pref_max(n), ans(n);
    pref_max[0] = a[0];
    for (int i = 1; i < n; ++i)
    {
        pref_max[i] = max(pref_max[i - 1], a[i]);
    }

    ans[n - 1] = pref_max[n - 1];
    // suffix min
    auto right_min = a[n - 1];
    for (int i = n - 2; i >= 0; --i)
    {
        ans[i] = (pref_max[i] > right_min) ? ans[i + 1] : pref_max[i];
        right_min = min(right_min, a[i]);
    }

    return ans;
}

int main()
{

    vector<int> nums = {2, 1, 3};
    vector<int> ans = maxValue(nums);
    for (auto &i : ans)
        cout << i << " ";
    cout << endl;

    return 0;
}