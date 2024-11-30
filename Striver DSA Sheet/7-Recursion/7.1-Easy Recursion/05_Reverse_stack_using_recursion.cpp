#include <bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int> &s, int element)
{
    if (s.empty())
    {
        s.push(element);
        return;
    }
    int temp = s.top();
    s.pop();
    insertAtBottom(s, element);
    s.push(temp);
}

void reverseStack(stack<int> &s)
{
    if (s.empty())
    {
        return;
    }
    int temp = s.top();
    s.pop();
    reverseStack(s);
    insertAtBottom(s, temp);
}

int main()
{
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    cout << "Original stack: ";
    stack<int> tempStack = s;
    while (!tempStack.empty())
    {
        cout << tempStack.top() << " ";
        tempStack.pop();
    }
    cout << endl;

    reverseStack(s);

    cout << "Reversed stack: ";
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}
