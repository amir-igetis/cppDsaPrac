#include <bits/stdc++.h>
using namespace std;

bool isOperator(string token)
{
    return (token == "+" || token == "-" ||
            token == "*" || token == "/");
}

int performOp(string op, int operand1, int operand2)
{
    if (op == "+")
        return operand1 + operand2;
    else if (op == "-")
        return operand1 - operand2;
    if (op == "*")
        return operand1 * operand2;
    else
        return operand1 / operand2;
}

int evalRPN(vector<string> &tokens)
{
    stack<int> st;
    for (string i : tokens)
    {
        if (isOperator(i))
        {
            int op2 = st.top(); // this is operand 2
            st.pop();
            int op1 = st.top(); // this is operand 1
            st.pop();
            int res = performOp(i, op1, op2);
            st.push(res);
        }
        else
        {
            int operand = stoi(i);
            st.push(operand);
        }
    }
    return st.top();
}

int main()
{
    vector<string> tokens = {"4", "13", "5", "/", "+"};
    cout << evalRPN(tokens) << endl;

    return 0;
}