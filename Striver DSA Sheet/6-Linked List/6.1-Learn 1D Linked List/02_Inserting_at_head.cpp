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
    Node *insertAtHead(Node *head, int val)
    {
        Node *temp = new Node(val);
        temp->next = head;
        return temp;
    }
};

int main()
{
    vector<int> arr = {12, 8, 5, 7};
    int val = 100;
    Node *head = new Node(arr[0]);
    head->next = new Node(arr[1]);
    head->next->next = new Node(arr[2]);
    head->next->next->next = new Node(arr[3]);

    Solution sol;
    Node *ans = sol.insertAtHead(head, val);
    while (ans)
    {
        cout << ans->data << " ";
        ans = ans->next;
    }
    cout << endl;
    return 0;
}