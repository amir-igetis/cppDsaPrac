#include <bits/stdc++.h>
using namespace std;

// binary indexed tree

/// Let n be the length of the array.
///
/// Time complexity: O(nlogn).
///
/// We iterate through the array of length n. In each iteration, updating the binary indexed tree and querying the range both take O(logn) time. Hash map lookups and insertions take O(1) time on average. Thus, the overall time complexity is O(nlogn).
///
/// Space complexity: O(n).
///
/// The binary indexed tree requires O(n) space for its internal arrays, and the hash map seen requires O(n) space to store the most recent index of each distinct element. Thus, the auxiliary space complexity is O(n).
class BIT
{
public:
    int size;
    vector<long long> _tree1;
    vector<long long> _tree2;

    BIT(int n)
    {
        size = n;
        _tree1.assign(n + 2, 0);
        _tree2.assign(n + 2, 0);
    }

    int _lowbit(int index) { return index & -index; }

    void add(int left, int right, int delta)
    {
        _add(left, delta);
        _add(right + 1, -delta);
    }

    long long query(int left, int right)
    {
        return _query(right) - _query(left - 1);
    }

private:
    void _add(int index, int delta)
    {
        index += 1;
        long long rawIndex = index;
        while (index <= size)
        {
            _tree1[index] += delta;
            _tree2[index] += rawIndex * delta;
            index += _lowbit(index);
        }
    }

    long long _query(int index)
    {
        index += 1;
        long long rawIndex = index + 1;
        if (index > size)
        {
            index = size;
        }
        long long res = 0;
        while (index > 0)
        {
            res += rawIndex * _tree1[index] - _tree2[index];
            index -= _lowbit(index);
        }
        return res;
    }
};

int sumCounts(vector<int> &A)
{
    int n = A.size();
    long long res = 0, cur = 0;
    BIT bit(n + 10);
    unordered_map<int, int> seen;
    long long mod = 1e9 + 7;
    for (int i = 0; i < n; i++)
    {
        int a = A[i];
        int j = (seen.count(a) ? seen[a] : -1) + 1;
        long long q = bit.query(j, i);
        cur = (cur + q * 2 + i - j + 1) % mod;
        res = (res + cur) % mod;
        bit.add(j, i, 1);
        seen[a] = i;
    }
    return res;
}

int main()
{

    vector<int> nums = {1, 2, 1};
    cout << sumCounts(nums);

    return 0;
}