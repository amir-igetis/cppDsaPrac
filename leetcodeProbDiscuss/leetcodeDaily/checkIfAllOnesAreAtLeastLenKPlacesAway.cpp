#include <bits/stdc++.h>
using namespace std;

bool kLengthApart(vector<int> &nums, int k)
{
    int prev = -1000000;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 1)
        {
            if (i - prev - 1 < k)
                return false;

            prev = i;
        }
    }
    return true;
}

bool kLengthApartI(vector<int> &nums, int k)
{
    int prev = -1;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 1)
        {
            if (prev != -1 && i - prev - 1 < k)
                return false;

            prev = i;
        }
    }
    return true;
}

int main()
{

    vector<int> nums = {1, 0, 0, 1, 0, 1};
    int k = 2;
    cout << (kLengthApart(nums, k) ? "True" : "False") << endl;

    return 0;
}