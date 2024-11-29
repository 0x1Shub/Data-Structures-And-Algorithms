// Find pairs with given sum in doubly linked list

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
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
        vector<pair<int, int>> result;
        Node *low = head, *high = head;
        while (high->next)
        {
            high = high->next;
        }
        while (low != high && low->data < high->data)
        {
            int req = target - low->data;
            while (low != high && high->data > req)
            {
                high = high->prev;
            }
            if (high->data == req && high != low)
            {
                result.push_back({low->data, high->data});
            }
            low = low->next;
        }
        return result;
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
    vector<pair<int, int>> result = sol.findPairsWithGivenSum(head, 7);

    cout << "Pairs with given sum: ";
    for (const auto &p : result)
    {
        cout << "(" << p.first << ", " << p.second << ") ";
    }
    cout << endl;

    return 0;
}
