// Search an element in a Linked List

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
    bool searchElement(Node *head, int target)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->data == target)
            {
                return true;
            }
            else
            {
                temp = temp->next;
            }
        }
        return false;
    }
};

int main()
{
    vector<int> arr = {1, 2, 3, 4};
    int target = 3;
    Node *head = new Node(arr[0]);
    head->next = new Node(arr[1]);
    head->next->next = new Node(arr[2]);
    head->next->next->next = new Node(arr[3]);

    Solution sol;
    if (sol.searchElement(head, target))
    {
        cout << "Target is present" << endl;
    }
    else
    {
        cout << "Target is not present" << endl;
    }
    return 0;
}