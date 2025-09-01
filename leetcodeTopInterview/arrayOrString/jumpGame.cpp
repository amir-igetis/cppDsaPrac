#include <bits/stdc++.h>
using namespace std;

bool canJump(vector<int> &nums)
{
    int goal = nums.size() - 1;
    for (int i = nums.size() - 2; i >= 0; i--)
    {
        if (i + nums[i] >= goal)
            goal = i;
    }
    return goal == 0;
}

int main()
{

    vector<int> vector = {2, 3, 1, 1, 4};
    cout << canJump(vector) << endl;
    return 0;
}