#include <bits/stdc++.h>
using namespace std;

// Sliding Window

/// Let n be the length of the given array nums.
///
/// Time complexity: O(nlogn).
///
/// Breaking down the costs:
///
/// Both sliding-window pointers left and right only move to the right, at most n times each, so there are O(n) window expansions and contractions in total.
/// During the scan, the decreasing monotonic stack maintains the nearest greater element to the left and finds the first greater-or-equal element to the right for each index. Each index is pushed and popped at most once, for a total cost of O(n).
/// Each window expansion retrieves the maximum from the priority queue to calculate the cost increase. After the window shrinks, queue-front elements outside the window are removed. Each index enters and leaves the queue at most once, so priority queue operations take O(nlogn) in total, with O(logn) per operation.
/// Shrinking the window requires traversing cnt[left], the set of indices covered by the removed element. Each index is covered by at most one element, so the sum of the sizes of all cnt sets is at most n. This part therefore takes O(n) in total.
/// Thus, the overall time complexity is O(nlogn).
/// Space complexity: O(n).
///
/// The array pos records the first greater-or-equal element to the right of each index, and cnt records the indices covered by each element. Their combined size is O(n). The decreasing monotonic stack and priority queue are each no larger than the window length, also requiring O(n) space.

long long countNonDecreasingSubarrays(vector<int> &nums, int k)
{
    int n = nums.size();
    long long ans = 0;
    long long operations = 0;
    // Maintain the window maximum with a priority queue
    priority_queue<pair<int, int>> q;
    // Record the set of elements covered by this index
    vector<vector<int>> cnt(n);
    // Index of the first greater-or-equal element to the right
    vector<int> pos(n, n);
    // Decreasing monotonic stack
    stack<int> st;

    for (int left = 0, right = 0; right < n; right++)
    {
        // Maintain the monotonic stack
        while (!st.empty() && nums[right] >= nums[st.top()])
        {
            pos[st.top()] = right;
            st.pop();
        }
        // The stack top is the nearest greater element to the left of
        // nums[right]
        if (!st.empty())
        {
            cnt[st.top()].push_back(right);
        }
        st.push(right);

        // The priority queue front is the window maximum
        q.emplace(nums[right], right);
        // Adding nums[right] increases the operation count
        operations += max(0, q.top().first - nums[right]);

        // The minimum operation count exceeds k; shrink the window
        while (operations > k)
        {
            // Removing nums[left] from the window decreases the operation
            // count
            for (int i : cnt[left])
            {
                // Subtract the contribution
                operations -=
                    (long long)(nums[left] - nums[i]) *
                    (min(pos[i], right + 1) - i);
            }
            left++;
        }

        // Remove elements with indices less than left from the priority
        // queue
        while (!q.empty() && q.top().second < left)
        {
            q.pop();
        }

        // There are right - left + 1 valid contiguous subarrays ending at
        // right
        ans += right - left + 1;
    }

    return ans;
}

int main()
{
    vector<int> nums = {6, 3, 1, 2, 4, 4};
    int k = 7;
    cout << countNonDecreasingSubarrays(nums, k) << endl;

    return 0;
}