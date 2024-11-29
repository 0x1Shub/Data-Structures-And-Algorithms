// Remove duplicates from a sorted doubly linked list

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int x)
    {
        data = x;
        next = nullptr;
        prev = nullptr;
    }
};

class Solution
{
public:
    void removeDuplicates(Node *head)
    {
        if (!head)
            return;

        Node *current = head;

        while (current->next)
        {
            if (current->data == current->next->data)
            {
                Node *temp = current->next;
                current->next = current->next->next;
                if (current->next)
                {
                    current->next->prev = current;
                }
                delete temp;
            }
            else
            {
                current = current->next;
            }
        }
    }
};

void printList(Node *head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    // Creating a sorted doubly linked list: 1<->1<->2<->2<->3<->4<->4<->5
    Node *head = new Node(1);
    head->next = new Node(1);
    head->next->prev = head;
    head->next->next = new Node(2);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(2);
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = new Node(3);
    head->next->next->next->next->prev = head->next->next->next;
    head->next->next->next->next->next = new Node(4);
    head->next->next->next->next->next->prev = head->next->next->next->next;
    head->next->next->next->next->next->next = new Node(4);
    head->next->next->next->next->next->next->prev = head->next->next->next->next->next;
    head->next->next->next->next->next->next->next = new Node(5);
    head->next->next->next->next->next->next->next->prev = head->next->next->next->next->next->next;

    cout << "Original list: ";
    printList(head);

    Solution sol;
    sol.removeDuplicates(head);

    cout << "List after removing duplicates: ";
    printList(head);

    return 0;
}
