#include <bits/stdc++.h>
using namespace std;

// Greedy

/// Let n be the length of the input string s.
///
/// Time complexity: O(n)
///
/// The algorithm iterates through each character in s exactly once. At each iteration, we perform constant time operations - checking character equality, modulo operation, and incrementing counters.
///
/// Thus, the time complexity is O(n).
///
/// Space complexity: O(1)
///
/// The algorithm uses only three variables regardless of the input size. These do not grow with the input size.
///
/// Thus, the space complexity of the algorithm is constant (O(1)).
int minChanges(string s)
{
    // Initialize with first character of string
    char currentChar = s[0];

    int consecutiveCount = 0;
    int minChangesRequired = 0;

    // Iterate through each character in the string
    for (int i = 0; i < s.length(); i++)
    {
        // If current character matches the previous sequence
        if (s[i] == currentChar)
        {
            consecutiveCount++;
            continue;
        }

        // If we have even count of characters, start new sequence
        if (consecutiveCount % 2 == 0)
        {
            consecutiveCount = 1;
        }
        // If odd count, we need to change current character
        // to match previous sequence
        else
        {
            consecutiveCount = 0;
            minChangesRequired++;
        }

        // Update current character for next iteration
        currentChar = s[i];
    }

    return minChangesRequired;
}

// Greedy (Optimized)

/// Let n be the length of the input string s.
///
/// Time complexity: O(n)
///
/// The algorithm iterates through the input string using a step size of 2. We examine each pair exactly once, performing n/2 comparisons in total. Each comparison takes constant time.
///
/// Thus, the time complexity is O(n).
///
/// Space complexity: O(1)
///
/// No additional space is used which scales with the input size, so the space complexity remains constant.

int minChangesI(string s)
{
    int minChangesRequired = 0;

    // Check pairs of characters (i, i+1) with step size 2
    for (int i = 0; i < s.length(); i += 2)
    {
        // If characters in current pair don't match,
        // we need one change to make them equal
        if (s[i] != s[i + 1])
        {
            minChangesRequired++;
        }
    }

    return minChangesRequired;
}

int main()
{
    string s = "010101";
    cout << minChanges(s) << endl;  // Output: 0
    cout << minChangesI(s) << endl; // Output: 0

    s = "0101010";
    cout << minChanges(s) << endl;  // Output: 1
    cout << minChangesI(s) << endl; // Output: 1

    s = "000111";
    cout << minChanges(s) << endl;  // Output: 2
    cout << minChangesI(s) << endl; // Output: 2

    return 0;
}