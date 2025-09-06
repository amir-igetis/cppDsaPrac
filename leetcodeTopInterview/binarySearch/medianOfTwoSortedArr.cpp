#include <bits/stdc++.h>
using namespace std;

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    int m = nums1.size(), n = nums2.size();
    vector<int> merged(m + n);
    int i = 0, j = 0, k = 0;

    while (i < m && j < n)
    {
        if (nums1[i] < nums2[j])
            merged[k++] = nums1[i++];
        else
            merged[k++] = nums2[j++];
    }

    while (i < m)
        merged[k++] = nums1[i++];

    while (j < n)
        merged[k++] = nums2[j++];

    int mid = m + (n - m) / 2;
    if ((m + n) % 2 == 0)
    {
        return (merged[mid - 1] + merged[mid]) / 2.0;
    }
    else
    {
        return merged[mid];
    }
}

int main()
{

    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};

    cout << findMedianSortedArrays(nums1, nums2) << endl;

    return 0;
}