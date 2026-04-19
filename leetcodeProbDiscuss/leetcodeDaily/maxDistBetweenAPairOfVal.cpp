#include <bits/stdc++.h>
using namespace std;

int maxDistance(vector<int> &nums1, vector<int> &nums2)
{
    int i = 0, j = 0;
    int maxDist = 0;
    while (i < nums1.size() && j < nums2.size())
    {
        if (nums1[i] <= nums2[j])
        {
            maxDist = max(maxDist, j - i);
            j++;
        }
        else
        {
            i++;
        }
    }
    return maxDist;
}

int main()
{
    vector<int> nums1 = {55, 30, 5, 4, 2}, nums2 = {100, 20, 10, 10, 5};
    cout << maxDistance(nums1, nums2) << endl;

    return 0;
}