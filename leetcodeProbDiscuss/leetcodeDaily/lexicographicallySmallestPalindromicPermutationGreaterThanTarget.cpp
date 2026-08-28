#include <bits/stdc++.h>
using namespace std;

// Sequential Enumeration

/// Let n be the length of the given string s, and let ∣Σ∣=26 be the size of the character set.
///
/// Time complexity: O(n∣Σ∣×(n+∣Σ∣)).
///
/// We first traverse s to count the frequency of each character and determine whether it can be rearranged into a palindrome, which takes O(n+∣Σ∣) time. We then construct the left half from left to right and try each possible character, resulting in at most O(n∣Σ∣) attempts. For each attempt, the check() function constructs a candidate palindrome in O(n+∣Σ∣) time. Therefore, the overall time complexity is O(n∣Σ∣(n+∣Σ∣)).
///
/// Space complexity: O(n+∣Σ∣).
///
/// The frequency array requires O(∣Σ∣) space, while the intermediate strings used during construction require O(n) space.
string lexPalindromicPermutation(string s, string target)
{
    int n = s.length();
    // Special case: length of 1
    if (n == 1)
    {
        return s > target ? s : "";
    }

    // Count the frequency of each character
    vector<int> cnt(26, 0);
    for (char c : s)
    {
        cnt[c - 'a']++;
    }

    // Check if it can form a palindrome and record the characters with odd
    // occurrences
    string oddChar = "";
    for (int i = 0; i < 26; i++)
    {
        if (cnt[i] % 2 == 1)
        {
            // More than one character appears an odd number of times,
            // cannot form a palindrome
            if (oddChar != "")
            {
                return "";
            }
            oddChar = string(1, 'a' + i);
        }
        cnt[i] /= 2; // It takes only half the characters to construct the
                     // left half
    }

    string prefix = "";

    auto check = [&](char c) -> bool
    {
        string left = prefix;
        left.push_back(c);
        for (int i = 25; i >= 0; i--)
        {
            left.append(cnt[i], 'a' + i);
        }

        string palindrome = left + oddChar;
        string reversed_left = left;
        reverse(reversed_left.begin(), reversed_left.end());
        palindrome += reversed_left;

        return palindrome > target;
    };

    // Construct the left part of each digit greedily
    for (int i = 0; i < n / 2; i++)
    {
        bool found = false;
        // Try to place the smallest character in lexicographical order
        for (int j = 0; j < 26; j++)
        {
            if (cnt[j] == 0)
            {
                continue;
            }

            cnt[j]--;
            if (check('a' + j))
            {
                // If the constructed palindrome is greater than target,
                // choose the character
                prefix.push_back('a' + j);
                found = true;
                break;
            }
            else
            {
                cnt[j]++; // Not meeting the conditions, reset the counter
            }
        }
        if (!found)
        {
            return ""; // Cannot construct a palindrome larger than target
        }

        if (prefix[i] >
            target[i])
        { // prefix is already greater than target
            string left = prefix;
            for (int j = 0; j < 26; j++)
            {
                left.append(cnt[j], 'a' + j);
            }
            string palindrome = left + oddChar;
            string reversed_left = left;
            reverse(reversed_left.begin(), reversed_left.end());
            palindrome += reversed_left;
            return palindrome;
        }
    }

    // Construct the final palindrome string
    string ans = prefix + oddChar;
    string reversed_prefix = prefix;
    reverse(reversed_prefix.begin(), reversed_prefix.end());
    ans += reversed_prefix;
    return ans;
}

int main()
{
    string s = "baba", target = "abba";
    cout << lexPalindromicPermutation(s, target) << endl;

    return 0;
}