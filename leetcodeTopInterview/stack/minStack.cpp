#include <bits/stdc++.h>
using namespace std;

class MinStack
{
public:
    stack<int> extra;
    stack<int> st;
    MinStack()
    {
    }

    void push(int val)
    {
        extra.push(val);
        if (st.empty() || val <= st.top())
            st.push(val);

        else
            st.push(st.top());
    }

    void pop()
    {
        if (!extra.empty())
        {
            extra.pop();
            st.pop();
        }
    }

    int top()
    {
        return extra.top();
    }

    int getMin()
    {
        return st.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */