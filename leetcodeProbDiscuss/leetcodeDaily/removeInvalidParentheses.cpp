#include <bits/stdc++.h>

// Backtracking

/// Time Complexity : O(2^N) since in the worst case we will have only left parentheses in the expression and for every bracket we will have two options i.e.
/// whether to remove it or consider it. Considering that the expression has N parentheses,
/// the time complexity will be O(2^N).
/// Space Complexity : O(N) because we are resorting to a recursive solution and for a recursive solution there is
/// always stack space used as internal function states are saved onto a stack during recursion. The maximum depth of recursion decides the stack space used.
/// Since we process one character at a time and the base case for the recursion is when we have processed all of the characters of the expression string,
/// the size of the stack would be O(N). Note that we are not considering the space required to store the valid expressions. We only count the intermediate space here.
class Solution
{
private:
    std::unordered_set<std::string> validExpressions;
    int minimumRemoved;

    void reset()
    {
        validExpressions.clear();
        minimumRemoved = INT_MAX;
    }

    void recurse(
        const std::string &s,
        int index,
        int leftCount,
        int rightCount,
        std::string &expression,
        int removedCount)
    {

        // If we have reached the end of the string
        if (index == static_cast<int>(s.length()))
        {
            // Check if the current expression is valid
            if (leftCount == rightCount)
            {
                if (removedCount <= minimumRemoved)
                {
                    if (removedCount < minimumRemoved)
                    {
                        validExpressions.clear();
                        minimumRemoved = removedCount;
                    }
                    validExpressions.insert(expression);
                }
            }
        }
        else
        {
            char currentCharacter = s[index];

            // If the character is neither '(' nor ')', keep it and move forward
            if (currentCharacter != '(' && currentCharacter != ')')
            {
                expression.push_back(currentCharacter);
                recurse(s, index + 1, leftCount, rightCount, expression, removedCount);
                expression.pop_back();
            }
            else
            {
                // Option 1: Discard the current parenthesis
                recurse(s, index + 1, leftCount, rightCount, expression, removedCount + 1);

                // Option 2: Keep the current parenthesis
                expression.push_back(currentCharacter);
                if (currentCharacter == '(')
                {
                    recurse(s, index + 1, leftCount + 1, rightCount, expression, removedCount);
                }
                else if (rightCount < leftCount)
                {
                    // Only recurse for ')' if it doesn't break validity
                    recurse(s, index + 1, leftCount, rightCount + 1, expression, removedCount);
                }
                expression.pop_back(); // Backtrack
            }
        }
    }

public:
    std::vector<std::string> removeInvalidParentheses(std::string s)
    {
        reset();
        std::string expression = "";
        recurse(s, 0, 0, 0, expression, 0);
        return std::vector<std::string>(validExpressions.begin(), validExpressions.end());
    }
};

// Limited Backtracking

/// Time Complexity : The optimization that we have performed is simply a better form of pruning. Pruning here is something that will vary from one test case to another.
/// In the worst case, we can have something like ((((((((( and the left_rem = len(S) and in such a case we can discard all of the characters because all are misplaced.
/// So, in the worst case we still have 2 options per parenthesis and that gives us a complexity of O(2^N).
/// Space Complexity : The space complexity remains the same i.e. O(N) as previous solution.
/// We have to go to a maximum recursion depth of N before hitting the base case. Note that we are not considering
/// the space required to store the valid expressions. We only count the intermediate space here.

class SolutionI
{
private:
    std::unordered_set<std::string> validExpressions;

    void recurse(
        const std::string &s,
        int index,
        int leftCount,
        int rightCount,
        int leftRem,
        int rightRem,
        std::string &expression)
    {

        if (index == static_cast<int>(s.length()))
        {
            if (leftRem == 0 && rightRem == 0)
            {
                validExpressions.insert(expression);
            }
        }
        else
        {
            char character = s[index];

            // Pruning / Discard branch: only remove if we still have quota left
            if ((character == '(' && leftRem > 0) || (character == ')' && rightRem > 0))
            {
                recurse(
                    s,
                    index + 1,
                    leftCount,
                    rightCount,
                    leftRem - (character == '(' ? 1 : 0),
                    rightRem - (character == ')' ? 1 : 0),
                    expression);
            }

            // Include branch
            expression.push_back(character);

            if (character != '(' && character != ')')
            {
                recurse(s, index + 1, leftCount, rightCount, leftRem, rightRem, expression);
            }
            else if (character == '(')
            {
                recurse(s, index + 1, leftCount + 1, rightCount, leftRem, rightRem, expression);
            }
            else if (rightCount < leftCount)
            {
                recurse(s, index + 1, leftCount, rightCount + 1, leftRem, rightRem, expression);
            }

            expression.pop_back(); // Backtrack
        }
    }

public:
    std::vector<std::string> removeInvalidParentheses(std::string s)
    {
        validExpressions.clear();
        int left = 0, right = 0;

        // Precompute exact count of misplaced '(' and ')'
        for (char c : s)
        {
            if (c == '(')
            {
                left++;
            }
            else if (c == ')')
            {
                if (left == 0)
                {
                    right++;
                }
                else
                {
                    left--;
                }
            }
        }

        std::string expression = "";
        recurse(s, 0, 0, 0, left, right, expression);
        return std::vector<std::string>(validExpressions.begin(), validExpressions.end());
    }
};

// --------------------------------------------------------------------------
// Driver Code
// --------------------------------------------------------------------------
int main()
{
    std::string s = "()())()";

    Solution sol;
    SolutionI solI;

    std::vector<std::string> res1 = sol.removeInvalidParentheses(s);
    std::vector<std::string> res2 = solI.removeInvalidParentheses(s);

    std::cout << "Solution (Standard Backtracking):\n[ ";
    for (const auto &str : res1)
        std::cout << "\"" << str << "\" ";
    std::cout << "]\n\n";

    std::cout << "SolutionI (Pruned Backtracking):\n[ ";
    for (const auto &str : res2)
        std::cout << "\"" << str << "\" ";
    std::cout << "]\n";

    return 0;
}
