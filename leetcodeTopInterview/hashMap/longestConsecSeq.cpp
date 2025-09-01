#include <bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int> &nums)
{
    if (nums.size() == 0)
        return 0;

    unordered_set<int> st;
    for (int i : nums)
        st.insert(i);

    int maxLen = 0;
    for (int i : st)
    {
        if ((st.find(i - 1) == st.end()))
        {
            int currNum = i;
            int currLen = 1;

            while ((st.find(currNum + 1) != st.end()))
            {
                currNum++;
                currLen++;
            }
            maxLen = max(maxLen, currLen);
        }
    }
    return maxLen;
}

int main()
{
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    cout << longestConsecutive(nums) << endl;

    return 0;
}