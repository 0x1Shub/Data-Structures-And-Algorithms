// Delete all occurrences of a given key in a doubly linked list

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
    void deleteAllOccurOfX(Node *&head, int val)
    {
        if (!head)
            return;

        Node *current = head;

        // Deleting all occurrences of the given key
        while (current)
        {
            if (current->data == val)
            {
                // Deleting the head node
                if (current == head)
                {
                    head = current->next;
                    if (head)
                        head->prev = nullptr;
                    delete current;
                    current = head;
                }
                else
                {
                    // Deleting any node other than head
                    Node *temp = current;
                    current->prev->next = current->next;
                    if (current->next)
                        current->next->prev = current->prev;
                    current = current->next;
                    delete temp;
                }
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
    // Creating a doubly linked list: 1<->2<->3<->2<->5<->2<->6
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(2);
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->prev = head->next->next->next;
    head->next->next->next->next->next = new Node(2);
    head->next->next->next->next->next->prev = head->next->next->next->next;
    head->next->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next->prev = head->next->next->next->next->next;

    cout << "Original list: ";
    printList(head);

    Solution sol;
    sol.deleteAllOccurOfX(head, 2);

    cout << "List after deleting all occurrences of 2: ";
    printList(head);

    return 0;
}
