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
    int lengthOfLoop(Node *head)
    {
        Node *slow = head;
        Node *fast = head;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow = fast)
            {
                return findLength(fast, slow);
            }
        }
        return 0;
    }

    int findLength(Node *fast, Node *slow)
    {
        int count = 1;
        fast = fast->next;
        while (slow != fast)
        {
            count++;
            fast = fast->next;
        }
        return count;
    }
};

int main()
{
    Node *node1 = new Node(1);
    Node *node2 = new Node(2);
    node1->next = node2;
    Node *node3 = new Node(3);
    node2->next = node3;
    Node *node4 = new Node(4);
    node3->next = node4;
    Node *node5 = new Node(5);
    node4->next = node5;
    node5->next = node2;
    Node *head = node1;

    Solution sol;
    cout << sol.lengthOfLoop(head) << endl;
    return 0;
}