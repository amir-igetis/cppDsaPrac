#include <bits/stdc++.h>
using namespace std;

class UniqueBinaryString
{
public:
    // ---------- Approach 1: Recursion ----------
    int n;
    unordered_set<string> numsSet;

    string findDifferentBinaryString(vector<string> &nums)
    {
        n = nums.size();
        numsSet.clear();

        for (string &s : nums)
            numsSet.insert(s);

        return generate("");
    }

    string generate(string curr)
    {
        if (curr.length() == n)
        {
            if (!numsSet.count(curr))
                return curr;
            return "";
        }

        string addZero = generate(curr + "0");
        if (!addZero.empty())
            return addZero;

        return generate(curr + "1");
    }

    // ---------- Approach 2: Integer iteration ----------
    string findDifferentBinaryStringI(vector<string> &nums)
    {
        unordered_set<int> integers;

        for (string &num : nums)
            integers.insert(stoi(num, nullptr, 2));

        int n = nums.size();

        for (int num = 0; num <= n; num++)
        {
            if (!integers.count(num))
            {
                string ans = bitset<32>(num).to_string();
                ans = ans.substr(32 - n);
                return ans;
            }
        }

        return "";
    }

    // ---------- Approach 3: Cantor's Diagonal Argument ----------
    string findDifferentBinaryStringII(vector<string> &nums)
    {
        string ans = "";

        for (int i = 0; i < nums.size(); i++)
        {
            char curr = nums[i][i];
            ans += (curr == '0') ? '1' : '0';
        }

        return ans;
    }
};

// Static variable definitions
// int UniqueBinaryString::n;
// unordered_set<string> UniqueBinaryString::numsSet;

int main()
{
    vector<string> nums = {"01", "10"};
    UniqueBinaryString sol;

    cout << sol.findDifferentBinaryStringII(nums) << endl;

    // cout << UniqueBinaryString::findDifferentBinaryStringII(nums) << endl;

    return 0;
}