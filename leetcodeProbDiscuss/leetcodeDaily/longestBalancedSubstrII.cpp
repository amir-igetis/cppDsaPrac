#include <bits/stdc++.h>
using namespace std;

// better solution
class Solution
{
public:
    void solve(string &s, char x, char y, int &maxi)
    {
        int n = s.size();

        int sum = 0;
        unordered_map<int, int> mp;
        mp[0] = -1;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == x)
            {
                sum += 1;
            }
            else if (s[i] == y)
            {
                sum -= 1;
            }
            else
            {
                mp.clear();
                mp[0] = i;
                sum = 0;

                continue;
            }

            if (mp.find(sum) != mp.end())
            {

                maxi = max(maxi, i - mp[sum]);
            }
            else
            {
                mp[sum] = i;
            }
        }
    }
    int longestBalanced(string s)
    {
        int n = s.size();

        int maxi = 1;

        // Case-1 All same

        int len = 1;

        for (int i = 1; i < n; i++)
        {

            if (s[i] == s[i - 1])
            {
                len++;
            }
            else
            {
                maxi = max(maxi, len);
                len = 1;
            }
        }
        maxi = max(maxi, len);

        // Case-2 -> 2 distinct characters

        solve(s, 'a', 'b', maxi);
        solve(s, 'b', 'c', maxi);
        solve(s, 'a', 'c', maxi);

        // Case -3  All 3 have same frequency
        map<pair<int, int>, int> mp;
        mp[{0, 0}] = -1;
        vector<int> count(3, 0);
        for (int i = 0; i < n; i++)
        {
            count[s[i] - 'a']++;

            int countAB = count[0] - count[1];
            int countAC = count[0] - count[2];

            if (mp.find({countAB, countAC}) != mp.end())
            {
                maxi = max(maxi, i - mp[{countAB, countAC}]);
            }
            else
            {
                mp[{countAB, countAC}] = i;
            }
        }

        return maxi;
    }
};

// another one
class SolutionI
{
public:
    int longestBalanced(string s)
    {
        int n = s.size();
        int ans = 0;
        auto maxSingleCount = [&](char c) -> int
        {
            int count = 0, maxCount = 0;
            for (int i = 0; i < n; i++)
            {
                if (s[i] == c)
                {
                    count++;
                }
                else
                {
                    count = 0;
                }
                if (count > maxCount)
                    maxCount = count;
            }
            return maxCount;
        };

        ans = max(ans, maxSingleCount('a'));
        ans = max(ans, maxSingleCount('b'));
        ans = max(ans, maxSingleCount('c'));

        auto maxDoubleCount = [&](char c) -> int
        {
            int maxCount = 0;
            map<int, int> firstOcc;
            int currParity = 0;
            firstOcc[0] = -1;
            char inc = 'd';
            for (int i = 0; i < n; i++)
            {
                if (s[i] == c)
                {
                    firstOcc.clear();
                    firstOcc[0] = i;
                    currParity = 0;
                }
                else
                {
                    if (inc == 'd')
                    {
                        inc = s[i];
                    }
                    if (s[i] == inc)
                    {
                        currParity++;
                    }
                    else
                    {
                        currParity--;
                    }

                    // it will be count.contains
                    if (firstOcc.count(currParity))
                    {
                        maxCount = max(maxCount, i - firstOcc[currParity]);
                    }
                    else
                    {
                        firstOcc[currParity] = i;
                    }
                }
            }
            return maxCount;
        };

        ans = max(ans, maxDoubleCount('a'));
        ans = max(ans, maxDoubleCount('b'));
        ans = max(ans, maxDoubleCount('c'));

        auto maxTripleCount = [&]() -> int
        {
            int maxCount = 0;
            map<pair<int, int>, int> firstOcc;
            pair<int, int> currParity = make_pair(0, 0);
            firstOcc[currParity] = -1;
            for (int i = 0; i < n; i++)
            {
                if (s[i] == 'a')
                {
                    currParity.first++;
                }
                else if (s[i] == 'b')
                {
                    currParity.first--;
                    currParity.second++;
                }
                else
                {
                    currParity.second--;
                }
                if (firstOcc.find(currParity) != firstOcc.end())
                {
                    maxCount = max(maxCount, i - firstOcc[currParity]);
                }
                else
                {
                    firstOcc[currParity] = i;
                }
            }
            return maxCount;
        };

        ans = max(ans, maxTripleCount());

        return ans;
    }
};

// most optimal

class SolutionII
{
public:
    int find2(const vector<char> &c, char x, char y)
    {
        int n = c.size();
        int max_len = 0;

        vector<int> first(2 * n + 1, -2);

        int clear_idx = -1;
        int diff = n;

        first[diff] = -1;

        for (int i = 0; i < n; i++)
        {

            if (c[i] != x && c[i] != y)
            {
                clear_idx = i;
                diff = n;
                first[diff] = clear_idx;
            }
            else
            {
                if (c[i] == x)
                    diff++;
                else
                    diff--;

                if (first[diff] < clear_idx)
                {
                    first[diff] = i;
                }
                else
                {
                    max_len = max(max_len, i - first[diff]);
                }
            }
        }

        return max_len;
    }

    int find3(const vector<char> &c)
    {

        long long state = LLONG_MAX / 2;
        unordered_map<long long, int> first;

        first[state] = -1;

        int max_len = 0;

        for (int i = 0; i < (int)c.size(); i++)
        {

            if (c[i] == 'a')
                state += 1000001LL;
            else if (c[i] == 'b')
                state -= 1000000LL;
            else
                state--;

            if (first.count(state))
            {
                max_len = max(max_len, i - first[state]);
            }
            else
            {
                first[state] = i;
            }
        }

        return max_len;
    }

    int longestBalancedI(string s)
    {

        vector<char> c(s.begin(), s.end());
        int n = c.size();

        int cur_a = 0, cur_b = 0, cur_c = 0;
        int max_a = 0, max_b = 0, max_c = 0;

        for (int i = 0; i < n; i++)
        {

            if (c[i] == 'a')
            {
                cur_a = (i > 0 && c[i - 1] == 'a') ? cur_a + 1 : 1;
                max_a = max(max_a, cur_a);
            }
            else if (c[i] == 'b')
            {
                cur_b = (i > 0 && c[i - 1] == 'b') ? cur_b + 1 : 1;
                max_b = max(max_b, cur_b);
            }
            else
            {
                cur_c = (i > 0 && c[i - 1] == 'c') ? cur_c + 1 : 1;
                max_c = max(max_c, cur_c);
            }
        }

        int res = max({max_a, max_b, max_c});

        res = max(res, find2(c, 'a', 'b'));
        res = max(res, find2(c, 'a', 'c'));
        res = max(res, find2(c, 'b', 'c'));

        res = max(res, find3(c));

        return res;
    }
};

int main()
{

    string s = "abacbcaaabbcc";
    SolutionII sol;

    cout << sol.longestBalancedI(s) << endl;

    return 0;
}
