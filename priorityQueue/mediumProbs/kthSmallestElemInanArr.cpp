#include <bits/stdc++.h>
using namespace std;

int kthSmallest(vector<int> &nums, int k)
{
    priority_queue<int> p;
    for (int i = 0; i < nums.size(); i++)
    {
        p.push(nums[i]);
        if (p.size() > k)
            p.pop();
    }
    return p.top();
}

int main()
{

    vector<int> nums = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    int k = 2;
    cout << kthSmallest(nums, k) << endl;
    return 0;
}