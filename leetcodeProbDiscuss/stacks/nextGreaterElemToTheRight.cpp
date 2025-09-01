#include <bits/stdc++.h>
using namespace std;

vector<int> NGER(int n, vector<int> arr)
{
    stack<int> st;
    vector<int> ans;
    for (int i = n - 1; i >= 0; i--)
    {
        while (st.size() > 0 && st.top() <= arr[i])
            st.pop();

        if (st.size() == 0)
            ans.push_back(-1);
        else
            ans.push_back(st.top());

        st.push(arr[i]);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
    // size of nums2 > nums1
    vector<int> query = NGER(nums2.size(), nums2);
    vector<int> ans;
    // key : nums2, value, : NGE
    unordered_map<int, int> mp;
    for (int i = 0; i < nums2.size(); i++)
    {
        mp[nums2[i]] = query[i];
    }
    for (int i = 0; i < nums1.size(); i++)
    {
        ans.push_back(mp[nums1[i]]);
    }
    return ans;
}

int main()
{

    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};

    vector<int> res = nextGreaterElement(nums1, nums2);

    for (auto it : res)
        cout << it << " ";
    cout << endl;

    return 0;
}