#include <bits/stdc++.h>
using namespace std;

class Queue
{
    stack<int> input, output;

public:
    void Push(int x)
    {
        while (!input.empty())
        {
            output.push(input.top());
            input.pop();
        }
        cout << "The element push is: " << x << endl;
        input.push(x);
        while (!output.empty())
        {
            input.push(output.top());
            output.pop();
        }
    }

    int Pop()
    {
        if (input.empty())
        {
            cout << "Stack is empty";
            exit(0);
        }
        int val = input.top();
        input.pop();
        return val;
    }

    int Top()
    {
        if (input.empty())
        {
            cout << "Stack is empty";
            exit(0);
        }
        return input.top();
    }

    int size()
    {
        return input.size();
    }
};

int main()
{
    Queue q;
    q.Push(3);
    q.Push(4);
    cout << "The element poped is " << q.Pop() << endl;
    q.Push(5);
    cout << "The top of the queue is " << q.Top() << endl;
    cout << "The size of the queue is " << q.size() << endl;
    return 0;
}