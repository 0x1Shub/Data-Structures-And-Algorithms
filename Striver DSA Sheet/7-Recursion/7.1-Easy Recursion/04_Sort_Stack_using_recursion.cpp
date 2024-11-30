#include <bits/stdc++.h>
using namespace std;

void sortedInsert(stack<int> &s, int element)
{
    if (s.empty() || s.top() < element)
    {
        s.push(element);
        return;
    }
    int temp = s.top();
    s.pop();
    sortedInsert(s, element);
    s.push(temp);
}

void sortStack(stack<int> &s)
{
    if (s.empty())
    {
        return;
    }
    int temp = s.top();
    s.pop();
    sortStack(s);
    sortedInsert(s, temp);
}

int main()
{
    stack<int> s;
    s.push(30);
    s.push(20);
    s.push(50);
    s.push(40);
    s.push(10);

    cout << "Original stack: ";
    stack<int> tempStack = s;
    while (!tempStack.empty())
    {
        cout << tempStack.top() << " ";
        tempStack.pop();
    }
    cout << endl;

    sortStack(s);

    cout << "Sorted stack: ";
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}
