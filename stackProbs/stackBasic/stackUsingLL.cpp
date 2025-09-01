#include <bits/stdc++.h>
using namespace std;

// Node structure for the linked list
struct Node
{
    int data;
    Node *next;
};

// Stack class using linked list
class Stack
{
private:
    Node *top;

public:
    // Constructor
    Stack()
    {
        top = nullptr;
    }

    // Destructor to free memory
    ~Stack()
    {
        while (!isEmpty())
        {
            pop();
        }
    }

    // Function to push an element onto the stack
    void push(int value)
    {
        Node *newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
        cout << "Pushed " << value << " onto the stack.\n";
    }

    // Function to pop an element from the stack
    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack underflow. Cannot pop from an empty stack.\n";
            return;
        }
        Node *temp = top;
        top = top->next;
        cout << "Popped " << temp->data << " from the stack.\n";
        delete temp;
    }

    // Function to check the top element
    int peek()
    {
        if (isEmpty())
        {
            cout << "Stack is empty.\n";
            return -1;
        }
        return top->data;
    }

    // Function to check if the stack is empty
    bool isEmpty()
    {
        return top == nullptr;
    }

    // Function to display the stack
    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is empty.\n";
            return;
        }
        Node *temp = top;
        cout << "Stack elements: ";
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    Stack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);

    stack.display();

    cout << "Top element is: " << stack.peek() << endl;

    stack.pop();
    stack.display();

    return 0;
}
