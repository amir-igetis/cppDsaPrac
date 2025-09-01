#include <bits/stdc++.h>
using namespace std;

class StackImp
{
private:
    int capacity; // Renamed from size to capacity
    int *arr;
    int topIndex; // Renamed from top to topIndex

public:
    StackImp()
    {
        topIndex = -1;
        capacity = 1000;
        arr = new int[capacity];
    }

    ~StackImp()
    {
        delete[] arr; // Free allocated memory
    }

    void push(int x)
    {
        if (topIndex + 1 >= capacity)
        {
            // Optional: Handle stack overflow if needed
            throw overflow_error("Stack overflow");
        }
        arr[++topIndex] = x;
    }

    int pop()
    {
        if (topIndex < 0)
        {
            // Optional: Handle stack underflow if needed
            throw underflow_error("Stack underflow");
        }
        return arr[topIndex--];
    }

    int top()
    {
        if (topIndex < 0)
        {
            // Optional: Handle stack underflow if needed
            throw underflow_error("Stack is empty");
        }
        return arr[topIndex];
    }

    int getSize() // Renamed from size to getSize
    {
        return topIndex + 1;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    StackImp st;
    st.push(4);
    st.push(6);
    st.push(7);

    cout << st.top() << endl; // Output the top element

    return 0;
}
