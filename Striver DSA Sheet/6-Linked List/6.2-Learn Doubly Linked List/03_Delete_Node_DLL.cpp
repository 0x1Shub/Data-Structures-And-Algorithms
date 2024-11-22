// Delete Last Node & Head Node of a Doubly Linked List

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *back;

    Node(int x)
    {
        data = x;
        next = nullptr;
        back = nullptr;
    }
};

class Solution
{
public:
    Node *createDLL(vector<int> &arr)
    {
        Node *head = new Node(arr[0]);
        Node *temp = head;
        for (int i = 1; i < arr.size(); i++)
        {
            Node *newNode = new Node(arr[i]);
            temp->next = newNode;
            newNode->back = temp;
            temp = temp->next;
        }
        return head;
    }

    Node *deleteHead(Node *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return nullptr;
        }
        Node *prev = head;
        head = head->next;
        head->back = nullptr;
        prev->next = nullptr;
        return head;
    }

    Node *deleteTail(Node *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return nullptr;
        }

        Node *tail = head;
        while (tail->next != nullptr)
        {
            tail = tail->next;
        }

        Node *newTail = tail->back;
        newTail->next = nullptr;
        tail->back = nullptr;
        delete tail;
        return head;
    }
};

int main()
{
    vector<int> arr = {1, 2, 3, 4};
    Solution sol;
    Node *head = sol.createDLL(arr);
    Node *ans = sol.deleteTail(head);
    while (ans)
    {
        cout << ans->data << " ";
        ans = ans->next;
    }
    cout << endl;
    return 0;
}