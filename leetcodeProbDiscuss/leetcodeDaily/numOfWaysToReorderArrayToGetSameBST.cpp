#include <bits/stdc++.h>
using namespace std;

// recursion
/// Let m be the size of nums.
///
/// Time complexity: O(m^2)
///
/// In Java or C++, a table of Pascal's triangle of size m×m is built, which takes O(m ^2) time.
///
/// dfs(nums) recursively calls itself to process the left and right subtrees of the current node nums[0]. Since the total size of the subtrees decreases by 1 at each level of the recursion, the maximum height of the recursion tree is m. Thus the total time complexity of the recursive solution is O(m^2) because in each call we are doing O(m) work creating the subsequences.
///
/// Space complexity: O(m^2) or O(m)
///
/// In Java or C++, a table of Pascal's triangle of size m×m is built.
/// The recursive solution uses the call stack to keep track of the current subtree being processed. The maximum depth of the call stack is equal to the height of the BST constructed from the input array. In the worst case, nums may form a degenerate BST (e.g., a sorted array), which has a height of m−1, and the stack can hold up to m−1 calls, resulting in a space complexity of O(m).

class Solution
{
public:
    int numOfWays(vector<int> &nums)
    {
        int m = nums.size();
        // Table of Pascal's triangle
        table.resize(m + 1);
        for (int i = 0; i < m + 1; ++i)
        {
            table[i] = vector<long long>(i + 1, 1);
            for (int j = 1; j < i; ++j)
            {
                table[i][j] = (table[i - 1][j - 1] + table[i - 1][j]) % mod;
            }
        }

        return (dfs(nums) - 1) % mod;
    }

private:
    vector<vector<long long>> table;
    long long mod = 1e9 + 7;

    long long dfs(vector<int> &nums)
    {
        int m = nums.size();
        if (m < 3)
        {
            return 1;
        }

        vector<int> leftNodes, rightNodes;
        for (int i = 1; i < m; ++i)
        {
            if (nums[i] < nums[0])
            {
                leftNodes.push_back(nums[i]);
            }
            else
            {
                rightNodes.push_back(nums[i]);
            }
        }

        long long leftWays = dfs(leftNodes) % mod;
        long long rightWays = dfs(rightNodes) % mod;

        return (((leftWays * rightWays) % mod) * table[m - 1][leftNodes.size()]) % mod;
    }
};

int main()
{
    vector<int> nums = {2, 1, 3};
    Solution sol;
    cout << sol.numOfWays(nums) << endl;

    return 0;
}