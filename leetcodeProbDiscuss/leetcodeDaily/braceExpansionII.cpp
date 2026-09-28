#include<bits/stdc++.h>
using namespace std;

// recursive parsing

/// Let n be the length of expression, and M be the maximum number of words in any set (M≤2
/// n/5
///   in the worst case).
///
/// Time complexity: O(n⋅M).
///
/// Traversal takes O(n) time, while intermediate Cartesian products and unions process up to M strings of length up to O(n). With n≤60, M≤4096, easily running within time limits.
///
/// Space complexity: O(n⋅M).
///
/// Dominated by storing intermediate and final sets of strings of length up to O(n), alongside O(n) recursion stack space.
class Solution
{
    string expression;
    int idx;

    // item -> letter | { expr }
    set<string> item()
    {
        set<string> ret;
        if (expression[idx] == '{')
        {
            idx++;
            ret = expr();
        }
        else
        {
            ret = {string(1, expression[idx])};
        }
        idx++;
        return move(ret);
    }

    // term -> item | item term
    set<string> term()
    {
        // Initialize an empty set and take its Cartesian product with
        // subsequent results
        set<string> ret = {""};
        // An item starts with { or a lowercase letter; continue matching only
        // when this condition is met
        while (idx < expression.size() &&
               (expression[idx] == '{' || isalpha(expression[idx])))
        {
            auto sub = item();
            set<string> tmp;
            for (auto &left : ret)
            {
                for (auto &right : sub)
                {
                    tmp.insert(left + right);
                }
            }
            ret = move(tmp);
        }
        return move(ret);
    }

    // expr -> term | term, expr
    set<string> expr()
    {
        set<string> ret;
        while (true)
        {
            // Take the union with the result of term()
            // ret.merge(term());
            set<string> t = term();
            ret.insert(t.begin(), t.end());
            // Continue if a comma is matched; otherwise, stop matching
            if (idx < expression.size() && expression[idx] == ',')
            {
                idx++;
                continue;
            }
            else
            {
                break;
            }
        }
        return move(ret);
    }

public:
    vector<string> braceExpansionII(string expression)
    {
        this->expression = expression;
        this->idx = 0;
        auto ret = expr();
        return {ret.begin(), ret.end()};
    }
};

// stack

/// Let n be the length of expression, and M be the maximum number of words in any set (M≤2
/// n/5
///   in the worst case).
///
/// Time complexity: O(n⋅M)
///
/// Stack operations take O(n) time, while evaluating intermediate Cartesian products and unions processes up to M strings of length up to O(n). Because n≤60, M remains small, ensuring fast execution.
///
/// Space complexity: O(n⋅M)
///
/// Dominated by storing sets of strings on the operand stack, along with O(n) space for the stack structures themselves.
class SolutionI
{
public:
    vector<string> braceExpansionII(string expression)
    {
        vector<char> op;
        vector<set<string>> stk;

        // Pop the operator at the top of the stack and perform the calculation
        auto ope = [&]()
        {
            int l = stk.size() - 2, r = stk.size() - 1;
            if (op.back() == '+')
            {
                // stk[l].merge(stk[r]);
                stk[l].insert(stk[r].begin(), stk[r].end());
            }
            else
            {
                set<string> tmp;
                for (auto &left : stk[l])
                {
                    for (auto &right : stk[r])
                    {
                        tmp.insert(left + right);
                    }
                }
                stk[l] = move(tmp);
            }
            op.pop_back();
            stk.pop_back();
        };

        for (int i = 0; i < expression.size(); i++)
        {
            if (expression[i] == ',')
            {
                // Keep popping operators from the top of the stack until the
                // stack is empty or its top is not a multiplication sign
                while (op.size() && op.back() == '*')
                {
                    ope();
                }
                op.push_back('+');
            }
            else if (expression[i] == '{')
            {
                // First determine whether a multiplication sign needs to be
                // added, then push { onto the operator stack
                if (i > 0 &&
                    (expression[i - 1] == '}' || isalpha(expression[i - 1])))
                {
                    op.push_back('*');
                }
                op.push_back('{');
            }
            else if (expression[i] == '}')
            {
                // Keep popping operators from the top of the stack until its
                // top is {
                while (op.size() && op.back() != '{')
                {
                    ope();
                }
                op.pop_back();
            }
            else
            {
                // First determine whether a multiplication sign needs to be
                // added, then push the newly constructed set onto the set stack
                if (i > 0 &&
                    (expression[i - 1] == '}' || isalpha(expression[i - 1])))
                {
                    op.push_back('*');
                }
                stk.push_back({string(1, expression[i])});
            }
        }

        while (op.size())
        {
            ope();
        }
        return {stk.back().begin(), stk.back().end()};
    }
};

int main()
{
    string expression = "{a,b}{c,{d,e}}";
    Solution sol;
    vector<string> ans = sol.braceExpansionII(expression);
    for (const string &i : ans)
    {
        cout << i << ", ";
    }
    cout << endl;

    return 0;
}