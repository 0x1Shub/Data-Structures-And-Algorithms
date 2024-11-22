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

    Node *reverseDLL(Node *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        Node *prev = NULL;
        Node *curr = head;

        while (curr != NULL)
        {
            prev = curr->back;
            curr->back = curr->next;
            curr->next = prev;
            curr = curr->back;
        }

        return prev->back;
    }
};

int main()
{
    vector<int> arr = {1, 2, 3, 4};
    Solution sol;
    Node *head = sol.createDLL(arr);
    Node *ans = sol.reverseDLL(head);

    while (ans)
    {
        cout << ans->data << " ";
        ans = ans->next;
    }

    return 0;
}