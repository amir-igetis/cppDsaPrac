#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX_N = 100005;

struct Node
{
    ll value;
    int left;
};

using ListIt = list<Node>::iterator;

struct Pair
{
    ListIt first;
    ListIt second;
    ll cost;
    size_t firstLeft;
    size_t secondLeft;

    Pair() {}
    Pair(ListIt fi, ListIt se, ll cost)
        : first(fi),
          second(se),
          firstLeft(fi->left),
          secondLeft(se->left),
          cost(cost) {}
};

struct ComparePair
{
    bool operator()(const Pair &a, const Pair &b)
    {
        if (a.cost != b.cost)
        {
            return a.cost > b.cost;
        }
        return a.firstLeft > b.firstLeft;
    }
};

int minimumPairRemoval(vector<int> &nums)
{
    list<Node> list;
    bitset<MAX_N> merged;
    priority_queue<Pair, vector<Pair>, ComparePair> pq;

    int decreaseCount = 0;
    int count = 0;

    list.push_back({nums[0], 0});

    for (size_t i = 1; i < nums.size(); ++i)
    {
        list.push_back({nums[i], (int)i});

        auto curr = std::prev(list.end());
        auto prev = std::prev(curr);

        pq.push({prev, curr, prev->value + curr->value});

        if (nums[i - 1] > nums[i])
        {
            decreaseCount++;
        }
    }

    while (decreaseCount > 0 && !pq.empty())
    {
        auto top = pq.top();
        pq.pop();

        if (merged[top.firstLeft] || merged[top.secondLeft])
        {
            continue;
        }

        auto first = top.first;
        auto second = top.second;
        auto cost = top.cost;

        if (first->value + second->value != cost)
        {
            continue;
        }

        count++;

        if (first->value > second->value)
        {
            decreaseCount--;
        }

        ListIt prev =
            (first == list.begin()) ? list.end() : std::prev(first);
        ListIt next = std::next(second);

        if (prev != list.end())
        {
            if (prev->value > first->value && prev->value <= cost)
            {
                decreaseCount--;
            }
            if (prev->value <= first->value && prev->value > cost)
            {
                decreaseCount++;
            }
            pq.push({prev, first, prev->value + cost});
        }

        if (next != list.end())
        {
            if (second->value > next->value && cost <= next->value)
            {
                decreaseCount--;
            }
            if (second->value <= next->value && cost > next->value)
            {
                decreaseCount++;
            }
            pq.push({first, next, cost + next->value});
        }

        first->value = cost;
        merged[second->left] = 1;
        list.erase(second);
    }

    return count;
}

// another better solution
int minimumPairRemovalI(vector<int> &nums)
{
    int n = nums.size();
    if (n <= 1)
        return 0;

    vector<long long> arr(nums.begin(), nums.end());
    vector<bool> removed(n, false);

    // C++14 requires explicit template arguments for greater
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

    int sorted = 0;
    for (int i = 1; i < n; ++i)
    {
        pq.emplace(arr[i - 1] + arr[i], i - 1);
        if (arr[i] >= arr[i - 1])
            sorted++;
    }
    if (sorted == n - 1)
        return 0;

    int remaining = n;
    vector<int> prev(n), next(n);
    for (int i = 0; i < n; ++i)
    {
        prev[i] = i - 1;
        next[i] = i + 1;
    }

    while (remaining > 1)
    {
        // Replaced Structured Binding [sum, left] with manual pair access
        pair<long long, int> top = pq.top();
        long long sum = top.first;
        int left = top.second;
        pq.pop();

        int right = next[left];
        if (right >= n || removed[left] || removed[right] || arr[left] + arr[right] != sum)
            continue;

        int pre = prev[left];
        int nxt = next[right];

        if (arr[left] <= arr[right])
            sorted--;
        if (pre != -1 && arr[pre] <= arr[left])
            sorted--;
        if (nxt != n && arr[right] <= arr[nxt])
            sorted--;

        arr[left] += arr[right];
        removed[right] = true;
        remaining--;

        if (pre != -1)
        {
            pq.emplace(arr[pre] + arr[left], pre);
            if (arr[pre] <= arr[left])
                sorted++;
        }
        else
        {
            prev[left] = -1;
        }

        if (nxt != n)
        {
            prev[nxt] = left;
            next[left] = nxt;
            pq.emplace(arr[left] + arr[nxt], left);
            if (arr[left] <= arr[nxt])
                sorted++;
        }
        else
        {
            next[left] = n;
        }

        if (sorted == remaining - 1)
            return n - remaining;
    }
    return n;
}

int main()
{
    vector<int> nums = {5, 2, 3, 1};
    cout << minimumPairRemoval(nums) << endl;
    return 0;
}