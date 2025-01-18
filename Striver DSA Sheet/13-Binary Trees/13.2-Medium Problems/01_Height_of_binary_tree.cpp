// Maximum depth of a Binary Tree

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
    int maxiDepth(Node *root)
    {
        if (root == NULL)
        {
            return 0;
        }

        int lh = maxiDepth(root->left);
        int rh = maxiDepth(root->right);

        return 1 + max(lh, rh);
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

    Solution sol;
    int depth = sol.maxiDepth(root);

    cout << "Maximum depth of the binary tree: " << depth << endl;
    return 0;
}