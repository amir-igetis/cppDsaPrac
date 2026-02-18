#include <bits/stdc++.h>
using namespace std;

long long rob(vector<int> &nums, vector<int> &colors)
{
    int n = nums.size();
    if (n == 0)
        return 0;
    int prevok = nums[0];
    int prevno = 0;
    for (int i = 1; i < n; i++)
    {
        int newno = max(prevok, prevno);
        int newok = nums[i] + prevno;
        if (colors[i] != colors[i - 1])
            newok = max(newok, nums[i] + prevok);

        prevok = newok;
        prevno = newno;
    }
    return max(prevok, prevno);
}

int main()
{

    vector<int> nums = {1, 4, 3, 5};
    vector<int> colors = {1, 1, 2, 2};

    vector<int> numsI = {3, 1, 2, 4};
    vector<int> colorsI = {2, 3, 2, 2};

    vector<int> numsII = {10, 1, 3, 9};
    vector<int> colorsII = {1, 1, 1, 2};

    cout << rob(nums, colors) << endl;
    cout << rob(numsI, colorsI) << endl;
    cout << rob(numsII, colorsII) << endl;

    return 0;
}