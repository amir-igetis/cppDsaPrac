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

int main()
{

    int n = 4;
    vector<int> arr = {1, 3, 2, 4};
    vector<int> res = NGER(n, arr);
    for (int i = 0; i < n; i++)
        cout << res[i] << " ";
    cout << endl;

    return 0;
}