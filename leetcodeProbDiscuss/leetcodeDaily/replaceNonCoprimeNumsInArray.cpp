#include <bits/stdc++.h>
using namespace std;

// custom gcd func
int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

vector<int> replaceNonCoprimes(vector<int> &nums)
{
    vector<int> st;
    for (int x : nums)
    {
        st.push_back(x);
        while (st.size() > 1)
        {
            int a = st[st.size() - 2];
            int b = st.back();
            // int g = __gcd(a, b);
            int g = gcd(a, b);
            if (g == 1)
                break;
            long long lcm = (1LL * a * b) / g;
            st.pop_back();
            st.pop_back();
            st.push_back((int)lcm);
        }
    }
    return st;
}

int main()
{

    vector<int> nums = {2, 2, 1, 1, 3, 3, 3};
    vector<int> ans = replaceNonCoprimes(nums);
    for (int x : ans)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}