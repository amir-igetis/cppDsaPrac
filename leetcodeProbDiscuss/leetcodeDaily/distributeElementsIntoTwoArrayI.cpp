#include <bits/stdc++.h>
using namespace std;

// Two List Simulation
/// Let n be the length of the array nums.
///
/// Time complexity: O(n).
///
/// We traverse the array once, with each comparison and insertion taking O(1) time. Concatenating the two lists also takes O(n) time.
///
/// Space complexity: O(n).
///
/// The two lists together contain all n elements of the array.

vector<int> resultArray(vector<int> &nums)
{
    int n = nums.size();
    vector<int> arr1, arr2;
    arr1.push_back(nums[0]);
    arr2.push_back(nums[1]);
    for (int i = 2; i < n; i++)
    {
        if (arr1.back() > arr2.back())
        {
            arr1.push_back(nums[i]);
        }
        else
        {
            arr2.push_back(nums[i]);
        }
    }
    arr1.insert(arr1.end(), arr2.begin(), arr2.end());
    return arr1;
}

// Single Array with Two Pointers
/// Let n be the length of the array nums.
///
/// Time complexity: O(n).
///
/// We traverse the array in O(n) time and reverse part of the array in O(n) time. Therefore, the overall time complexity is O(n).
///
/// Space complexity: O(1).
///
/// Apart from the output array itself, we only use a constant number of additional variables, so the extra space complexity is O(1).
vector<int> resultArrayI(vector<int> &nums)
{
    int n = nums.size();
    vector<int> arr(n);
    arr[0] = nums[0];
    arr[n - 1] = nums[1];
    int idx = 0, revIdx = n - 1;
    for (int i = 2; i < n; i++)
    {
        if (arr[idx] > arr[revIdx])
        {
            arr[++idx] = nums[i];
        }
        else
        {
            arr[--revIdx] = nums[i];
        }
    }
    reverse(arr.begin() + revIdx, arr.end());
    return arr;
}

int main()
{
    vector<int> nums = {2, 1, 3};
    vector<int> result = resultArrayI(nums);
    for (auto &i : result)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}