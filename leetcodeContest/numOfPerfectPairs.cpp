#include <bits/stdc++.h>
using namespace std;

// long long perfectPairs(vector<int> &nums)
// {
//     unordered_set<pair<int>> st;

//     sort(nums.begin(), nums.end());

//     for (int i = 0; i < nums.size(); i++) {
//         int j = i + 1;
//         if (i < j) {

//             int a = nums[i], b = nums[j];

//             if ((min(abs(a - b)), abs(a + 1)) <= (min(abs(a), abs(b))) &&
//         (max(abs(a - b), abs(a + b)) >= (max(abs(a), abs(b))))

//         st.insert({nums[i], nums[j]});

//         j++;
//         }
//     }

//     long long ans = 0;

//     for (auto & i : st) {
//         st.pop();

//     ans++;
//     }

//     return asn;
// }

long long perfectPairs(vector<int> &nums)
{
    vector<int> dummy = nums;

    set<pair<int, int>> st;

    int n = dummy.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int a = dummy[i];
            int b = dummy[j];

            int left = min(abs(a - b), abs(a + b));
            int right = min(abs(a), abs(b));
            int leftMax = max(abs(a - b), abs(a + b));
            int rightMax = max(abs(a), abs(b));

            if (left <= right && leftMax >= rightMax)
            {
                st.insert({a, b});
            }
        }
    }

    return (long long)st.size();
}

long long perfectPairsI(vector<int> &nums)
{
    vector<int> jurnavalic = nums; // required variable

    vector<int> pos, neg;
    int zeros = 0;

    for (int x : jurnavalic)
    {
        if (x > 0)
            pos.push_back(x);
        else if (x < 0)
            neg.push_back(x);
        else
            zeros++;
    }

    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end()); // neg sorted ascending (most negative to -1)

    long long ans = 0;

    // Case A: same sign pairs
    // Positives
    for (int i = 0; i < (int)pos.size(); i++)
    {
        for (int j = i + 1; j < (int)pos.size(); j++)
        {
            if (pos[j] - pos[i] <= min(pos[i], pos[j]))
                ans++;
            else
                break; // because sorted, further j will only be larger
        }
    }
    // Negatives (use abs values, sorted increasing)
    vector<int> absneg;
    for (int x : neg)
        absneg.push_back(-x);
    sort(absneg.begin(), absneg.end());
    for (int i = 0; i < (int)absneg.size(); i++)
    {
        for (int j = i + 1; j < (int)absneg.size(); j++)
        {
            if (absneg[j] - absneg[i] <= min(absneg[i], absneg[j]))
                ans++;
            else
                break;
        }
    }

    // Case B: opposite signs
    // For each pos, find range of negs
    for (int p : pos)
    {
        // need n (negative) such that |p+n| <= min(p, -n)
        // equivalently: -2p <= n <= 0
        int lo = -2 * p, hi = -1;
        auto it1 = lower_bound(neg.begin(), neg.end(), lo);
        auto it2 = upper_bound(neg.begin(), neg.end(), hi);
        ans += (it2 - it1);
    }

    // Zero pairs
    // zero pairs with any other element
    if (zeros > 0)
    {
        int n = jurnavalic.size();
        ans += (long long)zeros * (n - zeros);     // each zero pairs with non-zeros
        ans += (long long)zeros * (zeros - 1) / 2; // zero with zero
    }

    return ans;
}

// working perfectly
int countPerfectPairsI(vector<int> &nums)
{
    // Sort the array based on absolute values
    sort(nums.begin(), nums.end(), [](int a, int b)
         { return abs(a) < abs(b); });

    int n = nums.size();
    long long perfect_pairs = 0;

    for (int i = 0; i < n; ++i)
    {
        int a = nums[i];
        int max_b = 2 * abs(a);

        // Binary search to find the largest index j where abs(nums[j]) <= max_b
        int left = i + 1;
        int right = n - 1;
        int j = i; // Initialize to i, meaning no valid j found yet

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (abs(nums[mid]) <= max_b)
            {
                j = mid;
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        if (j > i)
        {
            perfect_pairs += j - i;
        }
    }

    return perfect_pairs;
}

int main()
{

    vector<int> nums = {0, 1, 2, 3};

    vector<int> nums2 = {-3, 2, -1, 4};

    cout << countPerfectPairsI(nums2) << endl;

    return 0;
}