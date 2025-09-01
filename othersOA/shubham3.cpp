#include <bits/stdc++.h>

using namespace std;

void process_operations(const vector<string> &operations)
{
    multiset<int> stack;
    int top_element = -1;

    for (const string &op : operations)
    {
        stringstream ss(op);
        string command;
        ss >> command;

        if (command == "push")
        {
            int value;
            ss >> value;
            stack.insert(value);
            top_element = value;
        }
        else if (command == "pop")
        {
            if (!stack.empty())
            {
                auto it = stack.find(top_element);
                if (it != stack.end())
                {
                    stack.erase(it);
                }
                if (!stack.empty())
                {
                    top_element = *stack.rbegin();
                }
                else
                {
                    top_element = -1;
                }
            }
        }
        else if (command == "remove_lower")
        {
            int value;
            ss >> value;
            stack.erase(stack.begin(), stack.lower_bound(value));
            if (!stack.empty())
            {
                top_element = *stack.rbegin();
            }
            else
            {
                top_element = -1;
            }
        }
        else if (command == "remove_upper")
        {
            int value;
            ss >> value;
            stack.erase(stack.upper_bound(value), stack.end());
            if (!stack.empty())
            {
                top_element = *stack.rbegin();
            }
            else
            {
                top_element = -1;
            }
        }

        if (stack.empty())
        {
            cout << "EMPTY" << endl;
        }
        else
        {
            cout << top_element << endl;
        }
    }
}

int main()
{
    // vector<string> operations = {
    //     "push 3", "push 2", "push 4", "remove_lower 3", "remove_upper 3",
    //     "push 2", "pop", "pop"};
    // vector<string> operations = {
    //     "push 2", "remove_lower 2", "remove_lower 3", "push 5"};

    vector<string> operations = {
        "push 3", "push 2",
        "push 4",
        "remove_lower 3",
        "remove_upper 3", "push 2", "pop", "pop"};

    process_operations(operations);
    return 0;
}
