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
    Node *deleteNode(Node *root, int key)
    {
        if (root == NULL)
        {
            return NULL;
        }
        if (root->data == key)
        {
            return helper(root);
        }

        Node *dummy = root;
        while (root != NULL)
        {
            if (root->data > key)
            {
                if (root->left != NULL && root->left->data == key)
                {
                    root->left = helper(root->left);
                    break;
                }
                else
                {
                    root = root->left;
                }
            }
            else
            {
                if (root->right != NULL && root->right->data == key)
                {
                    root->right = helper(root->right);
                    break;
                }
                else
                {
                    root = root->right;
                }
            }
        }
        return dummy;
    }

    Node *helper(Node *root)
    {
        if (root->left == NULL)
        {
            return root->right;
        }
        else if (root->right == NULL)
        {
            return root->left;
        }
        Node *rightChild = root->right;
        Node *lastRight = findLastRight(root->left);
        lastRight->right = rightChild;
        return root->left;
    }

    Node *findLastRight(Node *root)
    {
        if (root->right == NULL)
        {
            return root;
        }
        return findLastRight(root->right);
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
    int key = 3;
    Node *ans = sol.deleteNode(root, key);
    cout << "After Deleting node in Binary Search Tree: " << endl;
    printInOrder(ans);
    cout << endl;
    return 0;
}