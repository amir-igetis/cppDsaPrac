#include <bits/stdc++.h>
using namespace std;

int minOperations(vector<int> &nums)
{
    vector<int> st;
    int res = 0;
    for (int num : nums)
    {
        while (!st.empty() && st.back() > num)
            st.pop_back();

        if (num == 0)
        {
            continue;
        }
        if (st.empty() || st.back() < num)
        {
            res++;
            st.push_back(num);
        }
    }
    return res;
}

int main()
{

    vector<int> nums = {1, 2, 1, 2, 1, 2};
    cout << minOperations(nums) << endl;

    return 0;
}