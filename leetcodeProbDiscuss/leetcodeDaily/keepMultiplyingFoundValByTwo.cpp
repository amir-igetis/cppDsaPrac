#include <bits/stdc++.h>
using namespace std;

int findFinalValue(vector<int> &nums, int original)
{
    unordered_set<int> st;
    for (auto &i : nums)
        st.insert(i);

    while (st.find(original) != st.end())
        original *= 2;

    return original;
}

int main()
{

    vector<int> nums = {5, 3, 6, 1, 12};
    int original = 3;

    cout << findFinalValue(nums, original) << endl;

    return 0;
}