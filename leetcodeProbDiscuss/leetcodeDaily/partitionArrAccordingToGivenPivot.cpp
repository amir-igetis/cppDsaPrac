#include <bits/stdc++.h>
using namespace std;

// dynamic lists tc & sc O(n)
vector<int> pivotArray(vector<int> &nums, int pivot)
{

    list<int> less;
    list<int> equal;
    list<int> greater;

    for (auto num : nums)
    {
        if (num < pivot)
        {
            less.push_back(num);
        }
        else if (num > pivot)
        {
            greater.push_back(num);
        }
        else
        {
            equal.push_back(num);
        }
    }

    less.insert(less.end(), equal.begin(), equal.end());
    less.insert(less.end(), greater.begin(), greater.end());

    vector<int> ans;
    for (auto num : less)
    {
        ans.push_back(num);
    }
    return ans;
}

// two passes with fixed arr tc & sc O(n)
vector<int> pivotArrayI(vector<int> &nums, int pivot)
{
    int less = 0;
    int equal = 0;
    for (int num : nums)
    {
        if (num < pivot)
            less++;
        else if (num == pivot)
            equal++;
    }

    vector<int> ans(nums.size());
    int lessI = 0;
    int equalI = less;
    int greaterI = less + equal;
    for (int i = 0; i < nums.size(); i++)
    {
        int num = nums[i];
        if (num < pivot)
        {
            ans[lessI] = num;
            lessI++;
        }
        else if (num > pivot)
        {
            ans[greaterI] = num;
            greaterI++;
        }
        else
        {
            ans[equalI] = num;
            equalI++;
        }
    }
    return ans;
}

int main()
{

    vector<int> nums = {9, 12, 5, 10, 14, 3, 10};
    int pivot = 10;
    vector<int> ans = pivotArrayI(nums, pivot);
    for (auto &i : ans)
        cout << i << " ";
    cout << endl;

    return 0;
}