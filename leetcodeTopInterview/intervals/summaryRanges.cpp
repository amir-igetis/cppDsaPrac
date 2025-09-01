#include <bits/stdc++.h>
using namespace std;

string format(int start, int end)
{
    if (start == end)
        return to_string(start);
    else
        return to_string(start) + "->" + to_string(end);
}

vector<string> summaryRanges(vector<int> &nums)
{
    vector<string> ans;
    if (nums.empty())
        return ans;

    int start = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] != nums[i - 1] + 1)
        {
            ans.push_back(format(start, nums[i - 1]));
            start = nums[i];
        }
    }
    ans.push_back(format(start, nums.back()));
    return ans;
}

int main()
{
    vector<int> nums = {0, 1, 2, 4, 5, 7};
    vector<string> res = summaryRanges(nums);

    for (auto &r : res)
        cout << r << " ";
    // Output: "0->2 4->5 7"

    return 0;
}
