#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *back;

    Node(int data1, Node *next1, Node *back1)
    {
        data = data1;
        next = next1;
        back = back1;
    }

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
    Node *constructDLL(vector<int> &arr)
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
};

int main()
{
    vector<int> arr = {1, 2, 3, 4};
    Solution sol;
    Node *ans = sol.constructDLL(arr);
    while (ans)
    {
        cout << ans->data << " ";
        ans = ans->next;
    }
    return 0;
}