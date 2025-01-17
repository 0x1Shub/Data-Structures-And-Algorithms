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
    void inorder(Node *root, vector<int> &ans)
    {
        if (root == NULL)
        {
            return;
        }
        inorder(root->left, ans);
        ans.push_back(root->data);
        inorder(root->right, ans);
    }

    vector<int> inorderTraversal(Node *root)
    {
        vector<int> ans;
        inorder(root, ans);
        return ans;
    }
};

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    Solution sol;
    vector<int> ans = sol.inorderTraversal(root);
    for (auto x : ans)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}