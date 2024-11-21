// Creating Linked List using array

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
    Node *createLinkedList(vector<int> &arr)
    {
        Node *head = new Node(arr[0]);
        Node *temp = head;
        for (int i = 1; i < arr.size(); i++)
        {
            Node *newNode = new Node(arr[i]);
            temp->next = newNode;
            temp = temp->next;
        }
        return head;
    }
};

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    Solution sol;
    Node *ans = sol.createLinkedList(arr);
    while (ans)
    {
        cout << ans->data << " ";
        ans = ans->next;
    }
    cout << endl;
    return 0;
}