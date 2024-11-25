#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = nullptr;
    }
};

class Solution
{
public:
    Node *reverseLL(Node *head)
    {
        Node *temp = head;
        Node *prev = NULL;

        while (temp != NULL)
        {
            Node *front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }
};

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    Solution sol;
    Node *ans = sol.reverseLL(head);
    while (ans)
    {
        cout << ans->data << " ";
        ans = ans->next;
    }
    cout << endl;
    return 0;
}