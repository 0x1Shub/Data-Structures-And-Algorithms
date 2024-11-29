// Segregate even and odd nodes in LinkedList

#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int x)
    {
        val = x;
        next = nullptr;
    }
};

ListNode *head, *tail;

void PrintList(ListNode *head)
{
    ListNode *curr = head;
    for (; curr != nullptr; curr = curr->next)
        cout << curr->val << "-->";
    cout << "null" << endl;
}

void InsertatLast(int value)
{

    ListNode *newnode = new ListNode(value);
    if (head == nullptr)
        head = newnode, tail = newnode;
    else
        tail = tail->next = newnode;
}

ListNode *SegregatetoOddEVen()
{
    ListNode *oddHead = new ListNode(-1), *oddTail = oddHead;
    ListNode *evenHead = new ListNode(-1), *evenTail = evenHead;
    ListNode *curr = head, *temp;
    while (curr)
    {
        temp = curr;
        curr = curr->next;
        temp->next = nullptr;

        if (temp->val & 1)
        {
            oddTail->next = temp;
            oddTail = temp;
        }
        else
        {
            evenTail->next = temp;
            evenTail = temp;
        }
    }
    evenTail->next = oddHead->next;
    return evenHead->next;
}

int main()
{
    InsertatLast(1);
    InsertatLast(2);
    InsertatLast(3);
    InsertatLast(4);
    cout << "Initial LinkedList : " << endl;
    PrintList(head);
    ListNode *newHead = SegregatetoOddEVen();
    cout << "LinkedList After Segregration " << endl;
    PrintList(newHead);
    return 0;
}