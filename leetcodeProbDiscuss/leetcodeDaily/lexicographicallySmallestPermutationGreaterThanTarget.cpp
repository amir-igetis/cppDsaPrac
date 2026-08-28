#include <bits/stdc++.h>
using namespace std;

// Sequential Enumeration

/// Let n be the length of the string, and let ∣Σ∣=26 be the size of the character set.
///
/// Time complexity: O(n×(n+∣Σ∣)).
///
/// For each position, we may try up to ∣Σ∣ characters. Each feasibility check constructs the maximum string in O(n) time and compares it with the corresponding suffix in O(n) time. Therefore, the total time complexity is O(n×(n+∣Σ∣)).
///
/// Space complexity: O(∣Σ∣).
///
/// The character count array requires O(∣Σ∣) space.

// Get the maximum lexicographical string (in descending order)
string getMaxString(const vector<int> &cnt)
{
    string res;
    for (int i = 25; i >= 0; i--)
    {
        res.append(cnt[i], 'a' + i);
    }
    return res;
}

// Check if the remaining characters can form a string greater than the
// suffix.
bool canFormGreater(const vector<int> &cnt, const string &target,
                    int start)
{
    string maxStr = getMaxString(cnt);
    string suffix = target.substr(start);
    return maxStr > suffix;
}
// Get the lexicographically smallest string (in ascending order)
string getMinString(const vector<int> &cnt)
{
    string res;
    for (int i = 0; i < 26; i++)
    {
        res.append(cnt[i], 'a' + i);
    }
    return res;
}

string lexGreaterPermutation(string s, string target)
{
    vector<int> cnt(26, 0);
    for (char c : s)
    {
        cnt[c - 'a']++;
    }

    string res;
    int n = target.size();
    for (int i = 0; i < n; i++)
    {
        int targetChar = target[i] - 'a';

        // Case 1: First try to place the same character as target[i] at the
        // current position
        if (cnt[targetChar] > 0)
        {
            cnt[targetChar]--;
            // Check if the remaining characters can form a string greater
            // than target[i+1:]
            if (canFormGreater(cnt, target, i + 1))
            {
                res.push_back(target[i]);
                continue;
            }
            // Cannot form a larger string, backtrack
            cnt[targetChar]++;
        }

        // Case 2: Place a character greater than target[i] at the current
        // position
        for (int j = targetChar + 1; j < 26; j++)
        {
            if (cnt[j] > 0)
            {
                cnt[j]--;
                res.push_back('a' + j);
                // Fill remaining positions with the smallest
                // lexicographical order
                res += getMinString(cnt);
                return res;
            }
        }

        // No feasible solution found, return directly
        return "";
    }

    return "";
}

// Reverse Greedy

/// Let n be the length of the given string, and let ∣Σ∣=26 be the size of the character set.
///
/// Time complexity: O(n∣Σ∣).
///
/// We enumerate each position of target from right to left. At each position, checking whether the prefix can be matched takes O(∣Σ∣) time, and finding a larger character also takes O(∣Σ∣) time. Therefore, the total time complexity is O(n∣Σ∣).
///
/// Space complexity: O(∣Σ∣)
///

/// The character count array requires O(∣Σ∣) space.

// Get the lexicographically smallest string (in ascending order)
string getMinStringI(const vector<int> &cnt)
{
    string res;
    for (int i = 0; i < 26; i++)
    {
        res.append(cnt[i], 'a' + i);
    }
    return res;
}

string lexGreaterPermutationI(string s, string target)
{
    vector<int> cnt(26);
    for (int i = 0; i < s.size(); i++)
    {
        cnt[s[i] - 'a']++;
        cnt[target[i] - 'a']--;
    }

    // Try from right to left
    for (int i = s.size() - 1; i >= 0; i--)
    {
        int b = target[i] - 'a';
        cnt[b]++; // Reversal of consumption
                  // Check if the prefix can fully match
        if (*min_element(cnt.begin(), cnt.end()) < 0)
        {
            continue;
        }
        // Find the smallest available character larger than b.
        for (int j = b + 1; j < 26; j++)
        {
            if (cnt[j])
            {
                cnt[j]--;
                target[i] = 'a' + j;
                target.resize(i + 1);
                return target + getMinStringI(cnt);
            }
        }
    }

    return "";
}

int main()
{
    string s = "abc", target = "bba";
    cout << lexGreaterPermutation(s, target) << endl;
    cout << lexGreaterPermutationI(s, target) << endl;

    return 0;
}