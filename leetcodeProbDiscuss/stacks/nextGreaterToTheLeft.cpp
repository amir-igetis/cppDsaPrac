#include <bits/stdc++.h>
using namespace std;

vector<int> NGEL(vector<int> &arr)
{
    stack<int> st;
    vector<int> res;
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        while (st.size() > 0 && st.top() <= arr[i])
            st.pop();

        if (st.size() == 0)
            res.push_back(-1);
        else
            res.push_back(st.top());

        st.push(arr[i]);
    }
    return res;
}

int main()
{

    vector<int> nums = {1, 3, 4, 2};
    vector<int> res = NGEL(nums);
    for (auto it : res)
        cout << it << " ";
    cout << endl;

    return 0;
}