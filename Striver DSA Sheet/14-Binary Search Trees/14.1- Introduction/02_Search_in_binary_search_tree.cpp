#include <bits/stdc++.h>
using namespace std;

struct Node
{
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
    Node *searchBST(Node *root, int target)
    {
        while (root != NULL && root->data != target)
        {
            root = target < root->data ? root->left : root->right;
        }
        return root;
    }

    void printNode(Node *root)
    {
        if (root == NULL)
        {
            return;
        }
        printNode(root->left);
        cout << root->data << " ";
        printNode(root->right);
    }
};

int main()
{
    Node *root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(8);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->left = new Node(6);
    root->right->right = new Node(10);

    Solution sol;
    cout << "Binary Search Tree" << endl;
    sol.printNode(root);
    cout << endl;

    int target = 6;
    Node *result = sol.searchBST(root, target);

    if (result != nullptr)
    {
        cout << "Value " << target << " found in the BST!" << endl;
    }
    else
    {
        cout << "Value " << target << " not found in the BST." << endl;
    }

    return 0;
}