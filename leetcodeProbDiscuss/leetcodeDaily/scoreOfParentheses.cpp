#include <bits/stdc++.h>
using namespace std;

// Counting Cores (O(N) Time, O(1) Space) — Most OptimalIf you look closely at the rules, the final score is entirely determined by the deepest () pairs (the "cores"). Every time you find a core (), it contributes $2^{depth}$ to the total score, where depth is how many outer parentheses wrap it.This approach completely eliminates the need for extra memory.
int scoreOfParentheses(string s)
{
    int score = 0;
    int depth = 0;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            depth++;
        }
        else
        {
            depth--;
            // If we find an immediate "()", it's a core.
            // Add 2^depth to the total score.
            if (s[i - 1] == '(')
            {
                score += 1 << depth; // 1 << depth is equivalent to pow(2, depth)
            }
        }
    }

    return score;
}

// Stack Approach (O(N) Time, O(N) Space)
// Since this problem involves nested structures, a Stack is the standard way most people solve it initially.
//
// The stack keeps track of the score at the current depth. When you see an open bracket (, you push 0 to start calculating the inner score. When you see a closing bracket ), you pop the inner score, calculate its multiplied value Math.max(2 * inner_score, 1), and add it to the score of the outer level.

int scoreOfParenthesesI(string s)
{
    stack<int> st;
    // Push 0 as the base score for the outermost layer
    st.push(0);

    for (char c : s)
    {
        if (c == '(')
        {
            // Start a new inner layer with a score of 0
            st.push(0);
        }
        else
        {
            // We closed a layer, calculate its score
            int innerScore = st.top();
            st.pop();

            int outerScore = st.top();
            st.pop();

            // If innerScore is 0, it means it was a direct "()", so score is 1.
            // Otherwise, it was "(A)", so score is 2 * innerScore.
            int currentScore = outerScore + max(2 * innerScore, 1);

            // Add the computed score back to the current outer layer
            st.push(currentScore);
        }
    }

    return st.top();
}

int main()
{
    string s = "(()(()))";
    cout << "Score of parentheses: " << scoreOfParentheses(s) << endl;
    cout << "Score of parentheses using stack: " << scoreOfParenthesesI(s) << endl;

    return 0;
}
