// Delete Last Node of Linked List

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
    Node *deleteLastNode(Node *head)
    {
        Node *temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
        return head;
    }
};

int main()
{
    vector<int> arr = {12, 3, 6, 83};
    Node *head = new Node(arr[0]);
    head->next = new Node(arr[1]);
    head->next->next = new Node(arr[2]);
    head->next->next->next = new Node(arr[3]);

    Solution sol;
    Node *ans = sol.deleteLastNode(head);
    while (ans)
    {
        cout << ans->data << " ";
        ans = ans->next;
    }
    cout << endl;
    return 0;
}