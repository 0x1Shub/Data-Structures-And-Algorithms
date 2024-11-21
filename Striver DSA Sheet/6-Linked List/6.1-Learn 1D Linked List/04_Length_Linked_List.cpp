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
    int lengthLinkedList(Node *head)
    {
        Node *temp = head;
        int count = 0;
        while (temp != NULL)
        {
            temp = temp->next;
            count++;
        }
        return count;
    }
};

int main()
{
    vector<int> arr = {12, 3, 5, 6};
    Node *head = new Node(arr[0]);
    head->next = new Node(arr[1]);
    head->next->next = new Node(arr[2]);
    head->next->next->next = new Node(arr[3]);

    Solution sol;
    cout << sol.lengthLinkedList(head) << endl;

    return 0;
}