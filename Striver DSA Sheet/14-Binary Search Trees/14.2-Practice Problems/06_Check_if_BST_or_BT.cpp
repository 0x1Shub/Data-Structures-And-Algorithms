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
    bool isValidBST(Node *root)
    {
        return isValidBSTRecursive(root, NULL, NULL);
    }

    bool isValidBSTRecursive(Node *root, Node *low, Node *high)
    {
        if (root == nullptr)
        {
            return true;
        }

        if (high != nullptr && root->data >= high->data)
        {
            return false;
        }

        if (low != nullptr && root->data <= low->data)
        {
            return false;
        }

        return isValidBSTRecursive(root->left, low, root) && isValidBSTRecursive(root->right, root, high);
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
    if (sol.isValidBST(root))
    {
        cout << "It is valid BST" << endl;
    }
    else
    {
        cout << "It is not valid BST" << endl;
    }
    return 0;
}