#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> &numbers, int target)
{
    if (numbers.empty())
        return {};

    int start = 0, end = numbers.size() - 1;
    while (start < end)
    {
        int sum = numbers[start] + numbers[end];
        if (sum > target)
            end--;
        else if (sum < target)
            start++;
        else
            return {start + 1, end + 1};
    }
    return {};
}

int main()
{

    vector<int> numbers = {2, 7, 11, 15};
    int target = 9;

    vector<int> ans = twoSum(numbers, target);

    for (int i : ans)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}