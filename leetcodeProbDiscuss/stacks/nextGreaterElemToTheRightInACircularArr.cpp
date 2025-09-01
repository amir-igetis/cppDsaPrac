#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElements(vector<int> &arr)
{
    stack<int> st;
    vector<int> res;
    int n = arr.size();

    for (int i = n - 1; i >= 0; i--)
        st.push(arr[i]);

    for (int i = n - 1; i >= 0; i--)
    {
        while (st.size() > 0 && st.top() <= arr[i])
            st.pop();

        if (st.size() == 0)
            res.push_back(-1);
        else
            res.push_back(st.top());

        st.push(arr[i]);
    }
    reverse(res.begin(), res.end());
    return res;
}

int main()
{

    vector<int> arr = {1, 3, 4, 2};
    vector<int> res = nextGreaterElements(arr);
    for (auto it : arr)
        cout << it << " ";
    cout << endl;

    return 0;
}