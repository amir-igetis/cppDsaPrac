#include <bits/stdc++.h>
using namespace std;

int sumSubarrayMins(vector<int> &arr)
{
    const int MOD = 1e9 + 7;
    int n = arr.size();
    vector<int> left(n), right(n);
    stack<int> st;

    for (int i = 0; i < n; ++i)
    {
        while (!st.empty() && arr[st.top()] > arr[i])
            st.pop();

        left[i] = (st.empty()) ? (i + 1) : (i - st.top());
        st.push(i);
    }

    while (!st.empty())
        st.pop();

    for (int i = n - 1; i >= 0; --i)
    {
        while (!st.empty() && arr[st.top()] >= arr[i])
            st.pop();

        right[i] = (st.empty()) ? (n - i) : (st.top() - i);
        st.push(i);
    }

    long long res = 0;
    for (int i = 0; i < n; ++i)
    {
        res = (res + (long long)arr[i] * left[i] * right[i]) % MOD;
    }

    return res;
}

int main()
{

    vector<int> arr = {3, 1, 2, 4};
    cout << sumSubarrayMins(arr) << endl;
    return 0;
}