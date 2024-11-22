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

    Node *insertDLL(Node *head, int val)
    {
        Node *temp = head;
        Node *newNode = new Node(val);

        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->back = temp;
        return head;
    }
};

int main()
{
    vector<int> arr = {1, 2, 3, 4};
    int val = 6;
    Solution sol;
    Node *head = sol.createDLL(arr);
    Node *ans = sol.insertDLL(head, val);

    while (ans)
    {
        cout << ans->data << " ";
        ans = ans->next;
    }
    return 0;
}
