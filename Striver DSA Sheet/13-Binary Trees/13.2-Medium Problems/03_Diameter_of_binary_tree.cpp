#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    int diameter = 0;
    int calculateHeight(Node *node)
    {
        if (node == nullptr)
        {
            return 0;
        }
        int leftHeight = calculateHeight(node->left);
        int rightHeight = calculateHeight(node->right);
        diameter = max(diameter, leftHeight + rightHeight);
        return 1 + max(leftHeight, rightHeight);
    }

    int diameterOfBinaryTree(Node *root)
    {
        calculateHeight(root);
        return diameter;
    }

    int optimal(Node *root)
    {
        int diameter = 0;
        height(root, diameter);
        return diameter;
    }

private:
    int height(Node *node, int &diameter)
    {
        if (!node)
        {
            return 0;
        }
        int lh = height(node->left, diameter);
        int rh = height(node->right, diameter);
        diameter = max(diameter, lh + rh);
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

    Solution solution;
    int diameter = solution.optimal(root);

    cout << "The diameter of the binary tree is: " << diameter << endl;

    return 0;
}
