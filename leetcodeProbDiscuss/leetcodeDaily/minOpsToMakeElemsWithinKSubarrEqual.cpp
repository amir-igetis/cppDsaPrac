#include <bits/stdc++.h>
using namespace std;

//  Sliding Window + Two Heaps + Mathematics + Dynamic Programming

/// Let n be the length of nums, and k be the number of subarrays to select.
///
/// Time complexity: O(nlogn+nk).
///
/// The sliding window performs O(n) insertions, transfers between heaps, and deletions in total. With lazy deletion, elements that have left the window but have not reached the heap top may remain in a heap. The actual heap size can therefore reach O(n) in the worst case, so each heap operation takes O(logn) time. Precomputing all window costs takes O(nlogn) time. Dynamic programming has O(nk) states, each with an O(1) transition, giving a total time complexity of O(nlogn+nk).
///
/// Space complexity: O(nk).
///
/// The two heaps, the lazy-deletion hash table, and the window-cost array ops each use at most O(n) space. The two-dimensional dynamic programming array dp uses O(nk) space, giving a total of O(nk)
class Solution
{
public:
    long long minOperations(vector<int> &nums, int x, int k)
    {
        int n = nums.size();
        priority_queue<int> left;
        priority_queue<int, vector<int>, greater<int>> right;
        unordered_map<int, int> delayed;
        int leftSize = 0, rightSize = 0;
        vector<long long> ops(n);
        long long sumL = 0, sumR = 0;

        auto prune = [&](auto &heap)
        {
            while (!heap.empty())
            {
                if (delayed[heap.top()])
                {
                    --delayed[heap.top()];
                    heap.pop();
                }
                else
                {
                    break;
                }
            }
        };

        auto balance = [&]()
        {
            if (leftSize > rightSize + 1)
            {
                int num = left.top();
                right.push(num);
                sumR += num;
                sumL -= num;
                left.pop();
                ++rightSize;
                --leftSize;
                prune(left);
            }
            else if (rightSize > leftSize)
            {
                int num = right.top();
                left.push(num);
                sumL += num;
                sumR -= num;
                right.pop();
                ++leftSize;
                --rightSize;
                prune(right);
            }
        };

        for (int i = 0; i < n; i++)
        {
            if (left.empty() || nums[i] <= left.top())
            {
                left.push(nums[i]);
                ++leftSize;
                sumL += nums[i];
            }
            else
            {
                right.push(nums[i]);
                ++rightSize;
                sumR += nums[i];
            }
            balance();
            if (i >= x)
            {
                int num = nums[i - x];
                if (num <= left.top())
                {
                    --leftSize;
                    ++delayed[num];
                    sumL -= num;
                    if (num == left.top())
                    {
                        prune(left);
                    }
                }
                else
                {
                    --rightSize;
                    ++delayed[num];
                    sumR -= num;
                    if (num == right.top())
                    {
                        prune(right);
                    }
                }
                balance();
            }

            if (i >= x - 1)
            {
                long long mid = left.top();
                ops[i] = sumR - sumL + mid * (leftSize - rightSize);
            }
        }

        vector<vector<long long>> dp(n, vector<long long>(k + 1, LLONG_MAX));

        for (int i = 0; i < n; i++)
        {
            dp[i][0] = 0;
        }
        for (int j = 1; j <= k; j++)
        {
            if (j == 1)
            {
                dp[x - 1][j] = ops[x - 1];
            }
            else
            {
                dp[j * x - 1][j] = dp[(j - 1) * x - 1][j - 1] + ops[j * x - 1];
            }
        }
        for (int j = 1; j <= k; j++)
        {
            for (int i = j * x; i < n; i++)
            {
                dp[i][j] = min(dp[i - x][j - 1] + ops[i], dp[i - 1][j]);
            }
        }

        return dp[n - 1][k];
    }
};

// Sliding Window + Ordered Multisets + Mathematics + Dynamic Programming (Rolling Arrays)

/// Let n be the length of nums, x be the length of each selected subarray, and k be the number of subarrays to select.
///
/// Time complexity: O(nlogx+nk).
///
/// With ordered multisets implemented using balanced trees, each insertion, lookup, deletion, and transfer takes O(logx) time. The window moves O(n) times, so precomputing all window costs takes O(nlogx) time. Dynamic programming has k layers, and resetting the rolling array and computing the transitions each take O(n) time per layer. The total time complexity is O(nlogx+nk).
///
/// Space complexity: O(n).
///
/// The two ordered multisets store O(x) elements in total. The window-cost array ops uses O(n) space, and the rolling arrays pre and cur together use O(n) space. Since x≤n, the total space complexity is O(n)
class SolutionI
{
    vector<long long> getCosts(const vector<int> &nums, int x)
    {
        int n = nums.size();
        vector<long long> ops(n);

        multiset<int> left, right;
        long long sumL = 0, sumR = 0;

        for (int i = 0; i < n; ++i)
        {
            int v = nums[i];
            if (left.empty() || v <= *left.rbegin())
            {
                left.insert(v);
                sumL += v;
            }
            else
            {
                right.insert(v);
                sumR += v;
            }
            if (i >= x)
            {
                v = nums[i - x];
                auto it = left.find(v);
                if (it != left.end())
                {
                    sumL -= v;
                    left.erase(it);
                }
                else
                {
                    it = right.find(v);
                    sumR -= v;
                    right.erase(it);
                }
            }
            if (left.size() > right.size() + 1)
            {
                auto it = prev(left.end());
                v = *it;
                right.insert(v);
                left.erase(it);
                sumL -= v;
                sumR += v;
            }
            else if (left.size() < right.size())
            {
                auto it = right.begin();
                v = *it;
                left.insert(v);
                right.erase(it);
                sumL += v;
                sumR -= v;
            }
            if (i >= x - 1)
            {
                long long mid = *left.rbegin();
                long long leftCost = mid * (long long)left.size() - sumL;
                long long rightCost = sumR - mid * (long long)right.size();
                ops[i] = leftCost + rightCost;
            }
        }
        return ops;
    }

public:
    long long minOperations(vector<int> &nums, int x, int k)
    {
        int n = nums.size();
        vector<long long> ops = getCosts(nums, x);
        vector<long long> pre(n + 1, 0);
        vector<long long> cur(n + 1, LLONG_MAX);

        for (int j = 1; j <= k; ++j)
        {
            fill(cur.begin(), cur.end(), LLONG_MAX);
            for (int i = j * x; i <= n; ++i)
            {
                cur[i] = min(cur[i - 1], pre[i - x] + ops[i - 1]);
            }
            pre.swap(cur);
        }
        return pre[n];
    }
};

int main()
{
    vector<int> nums = {5, -2, 1, 3, 7, 3, 6, 4, -1};
    int x = 3, k = 2;
    Solution solution;
    Solution solutionI;
    cout << solution.minOperations(nums, x, k) << endl;
    cout << solutionI.minOperations(nums, x, k) << endl;

    return 0;
}