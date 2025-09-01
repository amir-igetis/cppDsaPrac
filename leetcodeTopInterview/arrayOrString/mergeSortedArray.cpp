#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{

    int i = m - 1, j = n - 1;
    int k = m + n - 1;
    while (i >= 0 && j >= 0)
    {
        if (nums1[i] > nums2[j])
        {
            nums1[k--] = nums1[i--];
        }
        else
        {
            nums1[k--] = nums2[j--];
        }
    }

    while (j >= 0)
    {
        nums1[k--] = nums2[j--];
    }
}

void mergeI(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    while (m > 0 && n > 0)
    {
        if (nums1[m - 1] > nums2[n - 1])
        {
            nums1[m + n - 1] = nums1[m - 1];
            m--;
        }
        else
        {
            nums1[m + n - 1] = nums2[n - 1];
            n--;
        }
    }

    while (n > 0)
    {
        nums1[m + n - 1] = nums2[n - 1];
        n--;
    }
}

int main()
{
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    int m = 3;

    vector<int> nums2 = {2, 5, 6};
    int n = 3;

    merge(nums1, m, nums2, n);
}