#include <bits/stdc++.h>
using namespace std;

// Top-Down Dynamic Programming - Memoization

/// Let n be the length of the input string.
///
/// Time complexity: O(n⋅n)
///
/// The time complexity of the isValidString function can be analyzed by considering the number of unique subproblems that need to be solved. Since there are at most n⋅n unique subproblems (indexed by index and openCount), where n is the length of the input string, and each subproblem is computed only once (due to memoization), the time complexity is bounded by the number of unique subproblems. Therefore, the time complexity can be stated as O(n⋅n).
///
/// Space complexity: O(n⋅n)
///
/// The space complexity of the algorithm is primarily determined by two factors: the auxiliary space used for memoization and the recursion stack space. The memoization table, denoted as memo, consumes O(n⋅n) space due to its size being proportional to the square of the length of the input string. Additionally, the recursion stack space can grow up to O(n) in the worst case, constrained by the length of the input string, as each recursive call may add a frame to the stack. Therefore, the overall space complexity is the sum of these two components, resulting in O(n⋅n)+O(n), which simplifies to O(n⋅n).
bool isValidString(int index, int openCount,
                   const string &str, vector<vector<int>> &memo)
{
    // If reached end of the string, check if all brackets are balanced
    if (index == str.size())
    {
        return (openCount == 0);
    }

    // If already computed, return memoized result
    if (memo[index][openCount] != -1)
    {
        return memo[index][openCount];
    }

    bool isValid = false;
    // If encountering '*', try all possibilities
    if (str[index] == '*')
    {
        isValid |= isValidString(index + 1, openCount + 1, str, memo); // Treat '*' as '('
        if (openCount)
        {
            isValid |= isValidString(index + 1, openCount - 1, str, memo); // Treat '*' as ')'
        }
        isValid |= isValidString(index + 1, openCount, str, memo); // Treat '*' as empty
    }
    else
    {
        // Handle '(' and ')'
        if (str[index] == '(')
        {
            isValid = isValidString(index + 1, openCount + 1, str, memo); // Increment count for '('
        }
        else if (openCount)
        {
            isValid = isValidString(index + 1, openCount - 1, str, memo); // Decrement count for ')'
        }
    }

    // Memoize and return the result
    return memo[index][openCount] = isValid;
}

bool checkValidString(string s)
{
    vector<vector<int>> memo(s.size(), vector<int>(s.size(), -1));
    return isValidString(0, 0, s, memo);
}

// Bottom-Up Dynamic Programming - Tabulation

/// Let n be the length of the input string.
///
/// Time complexity: O(n⋅n)
///
/// This is due to the nested loop structure, where the outer loop iterates over each character of the string, and the inner loop iterates over all possible counts of opening brackets.
///
/// Space complexity: O(n⋅n)
///
/// This is primarily due to the 2D array dp, which has dimensions (n+1)⋅(n+1).

bool checkValidStringI(string s)
{
    int n = s.size();
    // dp[index][openBracket] represents if the substring starting from index i is valid with j opening brackets
    vector<vector<bool>> dp(n + 1, vector<bool>(n + 1, false));
    // base case: an empty string with 0 opening brackets is valid
    dp[n][0] = true;

    for (int index = n - 1; index >= 0; index--)
    {
        for (int openBracket = 0; openBracket <= n; openBracket++)
        {
            bool isValid = false;

            // '*' can represent '(' or ')' or '' (empty)
            if (s[index] == '*')
            {
                isValid |= dp[index + 1][openBracket + 1]; // try '*' as '('

                // opening brackets to use '*' as ')'
                if (openBracket > 0)
                {
                    isValid |= dp[index + 1][openBracket - 1]; // try '*' as ')'
                }
                isValid |= dp[index + 1][openBracket]; // ignore '*'
            }
            else
            {
                // If the character is not '*', it can be '(' or ')'
                if (s[index] == '(')
                {
                    isValid |= dp[index + 1][openBracket + 1]; // try '('
                }
                else if (openBracket > 0)
                {
                    isValid |= dp[index + 1][openBracket - 1]; // try ')'
                }
            }
            dp[index][openBracket] = isValid;
        }
    }

    return dp[0][0]; // True if the entire string is valid with no excess opening brackets
}

// Using Two Stacks

/// Let n be the length of the input string.
///
/// Time complexity: O(n)
///
/// The algorithm iterates through the entire string once, taking O(n) time. Additionally, in the worst case, it may need to traverse both the openBrackets and asterisks stacks simultaneously to check for balanced parentheses, which also takes O(n) time. Thus, the overall time complexity is O(n).
///
/// Space complexity: O(n)
///
/// The algorithm uses two stacks, openBrackets, and asterisks, which could potentially hold up to O(n) elements combined in the worst case. Additionally, there are a few extra variables and loop counters, which require constant space. Therefore, the overall space complexity is O(n).
bool checkValidStringII(string s)
{
    stack<int> openBrackets; // Stack to store indices of open brackets
    stack<int> asterisks;    // Stack to store indices of asterisks

    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];

        // If current character is an open bracket, push its index onto the stack
        if (ch == '(')
        {
            openBrackets.push(i);
            // If current character is an asterisk, push its index onto the stack
        }
        else if (ch == '*')
        {
            asterisks.push(i);
            // current character is a closing bracket ')'
        }
        else
        {
            // If there are open brackets available, use them to balance the closing bracket
            if (!openBrackets.empty())
            {
                openBrackets.pop();
                // If no open brackets are available, use an asterisk to balance the closing bracket
            }
            else if (!asterisks.empty())
            {
                asterisks.pop();
                // Unmatched ')' and no '*' to balance it.
            }
            else
            {
                return false;
            }
        }
    }

    // Check if there are remaining open brackets and asterisks that can balance them
    while (!openBrackets.empty() && !asterisks.empty())
    {
        // If an open bracket appears after an asterisk, it cannot be balanced, return false
        if (openBrackets.top() > asterisks.top())
        {
            return false; // '*' before '(' which cannot be balanced.
        }
        openBrackets.pop();
        asterisks.pop();
    }

    // If all open brackets are matched and there are no unmatched open brackets left, return true
    return openBrackets.empty();
}

// Two Pointer

/// Let n be the length of the input string.
///
/// Time complexity: O(n)
///
/// The time complexity is O(n), as we iterate through the string once.
///
/// Space complexity: O(1)
///
/// The space complexity is O(1), as we use a constant amount of extra space to store the openCount and closeCount variables.

bool checkValidStringIII(string s)
{
    int openCount = 0;
    int closeCount = 0;
    int length = s.length() - 1;

    // Traverse the string from both ends simultaneously
    for (int i = 0; i <= length; i++)
    {
        // Count open parentheses or asterisks
        if (s[i] == '(' || s[i] == '*')
        {
            openCount++;
        }
        else
        {
            openCount--;
        }

        // Count close parentheses or asterisks
        if (s[length - i] == ')' || s[length - i] == '*')
        {
            closeCount++;
        }
        else
        {
            closeCount--;
        }

        // If at any point open count or close count goes negative, the string is invalid
        if (openCount < 0 || closeCount < 0)
        {
            return false;
        }
    }

    // If open count and close count are both non-negative, the string is valid
    return true;
}

int main()
{
    string s = "()";
    cout << (checkValidString(s) ? "true" : "false") << endl;
    cout << (checkValidStringI(s) ? "true" : "false") << endl;
    cout << (checkValidStringII(s) ? "true" : "false") << endl;
    cout << (checkValidStringIII(s) ? "true" : "false") << endl;

    return 0;
}