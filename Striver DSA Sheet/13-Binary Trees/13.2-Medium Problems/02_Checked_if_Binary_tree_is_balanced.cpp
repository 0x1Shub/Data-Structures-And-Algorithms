// Check if the Binary Tree is Balanced Binary Tree

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
    bool checkBalanceTree(Node *root)
    {
        if (root == NULL)
        {
            return true;
        }

        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);

        if (abs(leftHeight - rightHeight) <= 1 && checkBalanceTree(root->left) &&
            checkBalanceTree(root->right))
        {
            return true;
        }
    }

    int getHeight(Node *root)
    {
        if (root == NULL)
        {
            return 0;
        }

        int lh = getHeight(root->left);
        int rh = getHeight(root->right);

        return 1 + max(lh, rh);
    }

    bool optimal(Node *root)
    {
        return dfsHeight(root) != -1;
    }

    int dfsHeight(Node *root)
    {
        if (root == NULL)
        {
            return 0;
        }

        int lh = dfsHeight(root->left);
        if (lh == -1)
        {
            return -1;
        }

        int rh = dfsHeight(root->right);
        if (rh == -1)
        {
            return -1;
        }

        if (abs(lh - rh) > 1)
        {
            return -1;
        }

        return max(lh, rh) + 1;
    }
};

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(6);
    root->left->right->right->right = new Node(7);
    Solution solution;
    if (solution.optimal(root))
    {
        cout << "The tree is balanced." << endl;
    }
    else
    {
        cout << "The tree is not balanced." << endl;
    }
    return 0;
}