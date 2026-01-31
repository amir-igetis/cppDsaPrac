// #include <bits/stdc++.h>
// using namespace std;

// bool checkBYK(vector<int> &nums, int k)
// {
//     long long op = 0;
//     for (auto &i : nums)
//     {
//         op += (i + k - 1) / k;
//         if (op > 1LL * k * k)
//             return false;
//     }
//     return true;
// }

// int minimumK(vector<int> &nums)
// {
//     int maxi = 1;
//     for (auto &i : nums)
//         maxi = max(i, maxi);

//     int start = 1, end = maxi;
//     int ans = maxi;
//     while (start <= end)
//     {
//         int mid = start + (end - start) / 2;
//         if (checkBYK(nums, mid))
//         {
//             ans = mid;
//             end = mid - 1;
//         }
//         else
//             start = mid + 1;
//     }
//     return ans;
// }
// int main()
// {
//     vector<int> nums = {3, 7, 5};
//     cout << minimumK(nums) << endl;

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

// FIX 1: change check function logic
bool checkBYK(const vector<int>& nums, int k)
{
    long long ops = 0;
    for (int x : nums)
    {
        ops += (x + k - 1) / k;     // ceil(x / k)
        if (ops > 1LL * k * k)     // early exit
            return false;
    }
    return true;
}

int minimumK(vector<int> &nums)
{
    int maxi = 1;
    for (auto &i : nums)
        maxi = max(i, maxi);

    int start = 1, end = maxi;
    int ans = maxi;                // FIX 2: store answer

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (checkBYK(nums, mid))
        {
            ans = mid;             // FIX 3: don't return immediately
            end = mid - 1;         // FIX 4: correct binary search
        }
        else
        {
            start = mid + 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> nums = {3, 7, 5};
    cout << minimumK(nums) << endl; // Output: 3

    vector<int> nums2 = {1, 1};
    cout << minimumK(nums2) << endl; // Output: 2

    return 0;
}
