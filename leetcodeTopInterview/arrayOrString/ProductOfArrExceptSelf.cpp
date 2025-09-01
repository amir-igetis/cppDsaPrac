#include <bits/stdc++.h>
using namespace std;

vector<int> productExceptSelf(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans(n);
    ans[0] = 1;
    for (int i = 1; i < n; i++)
        ans[i] = ans[i - 1] * nums[i - 1];

    int suffixProd = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        ans[i] *= suffixProd;
        suffixProd *= nums[i];
    }

    return ans;
}

int main()
{

    vector<int> nums = {1, 2, 3, 4};
    vector<int> res = productExceptSelf(nums);

    for (auto &i : res)
        cout << i << " ";
    cout << endl;

    return 0;
}