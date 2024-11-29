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
    Node *reverseLL(Node *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        Node *newHead = reverseLL(head->next);
        Node *front = head->next;
        front->next = head;
        head->next = NULL;

        return newHead;
    }

    bool isPalindrome(Node *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return true;
        }
        Node *slow = head;
        Node *fast = head;

        while (fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        Node *newHead = reverseLL(slow->next);
        Node *first = head;
        Node *second = newHead;
        while (second != NULL)
        {
            if (first->data != second->data)
            {
                reverseLL(newHead);
                return false;
            }
            first = first->next;
            second = second->next;
        }
        reverseLL(newHead);
        return true;
    }
};

int main()
{
    Node *head = new Node(1);
    head->next = new Node(5);
    head->next->next = new Node(2);
    head->next->next->next = new Node(5);
    head->next->next->next->next = new Node(1);

    Solution sol;
    if (sol.isPalindrome(head))
    {
        cout << 'LL is palindrome' << endl;
    }
    else
    {
        cout << "LL is not palindrome" << endl;
    }
    return 0;
}