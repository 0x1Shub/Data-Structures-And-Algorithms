#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

class Solution
{
public:
    int floorValue(Node *root, int key)
    {
        int floor = -1;

        while (root)
        {
            if (root->data == key)
            {
                floor = root->data;
                return floor;
            }
            else if (key > root->data)
            {
                floor = root->data;
                root = root->right;
            }
            else
            {
                root = root->left;
            }
        }
        return floor;
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
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(13);
    root->left->left = new Node(3);
    root->left->left->left = new Node(2);
    root->left->left->right = new Node(4);
    root->left->right = new Node(6);
    root->left->right->right = new Node(9);
    root->right->left = new Node(11);
    root->right->right = new Node(14);

    cout << "Binary Search Tree: " << endl;
    printInOrder(root);
    cout << endl;

    Solution solution;
    int target = 8;
    int floor = solution.floorValue(root, target);

    if (floor != -1)
    {
        cout << "Floor value of " << target << " is: " << floor << endl;
    }
    else
    {
        cout << "No floor value found!";
    }

    return 0;
}