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
    int minValue(Node *root)
    {
        while (root != NULL && root->left != NULL)
        {
            root = root->left;
        }
        return root->data;
    }
};

int main()
{
    Node *root = new Node(5);
    root->left = new Node(4);
    root->right = new Node(6);
    root->left->left = new Node(3);
    root->left->right = NULL;
    root->right->left = NULL;
    root->right->right = new Node(7);
    root->left->left->left = new Node(1);
    root->left->left->right = NULL;

    Solution sol;
    int ans = sol.minValue(root);
    cout << "The minimum value in BST is: " << ans << endl;
    return 0;
}