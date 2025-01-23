#include <bits/stdc++.h>
using namespace std;

struct Node
{
public:
    int data;
    Node *right;
    Node *left;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

class Solution
{
public:
    Node *lowestCommonAncestor(Node *root, Node *p, Node *q)
    {
        if (root->data > max(p->data, q->data))
            return lowestCommonAncestor(root->left, p, q);
        if (root->data < min(p->data, q->data))
            return lowestCommonAncestor(root->right, p, q);
        return root;
    }
};

void printInOrder(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    printInOrder(root->left);
    cout << root->data << " ";
    printInOrder(root->right);
}

int main()
{
    Node *root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(6);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->left = NULL;
    root->right->right = new Node(7);

    cout << "Binary Search Tree: " << endl;
    printInOrder(root);
    cout << endl;

    Solution sol;
    Node *p = root->left;
    Node *q = root->right;
    Node *ans = sol.lowestCommonAncestor(root, p, q);
    cout << "Lowest Common Ancestor of nodes with values " << p->data << " and " << q->data << " is: " << ans->data << endl;

    return 0;
}
