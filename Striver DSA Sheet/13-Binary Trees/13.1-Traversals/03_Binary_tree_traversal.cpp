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
    void inorder(Node *root, vector<int> &temp)
    {
        if (root == NULL)
        {
            return;
        }
        inorder(root->left, temp);
        temp.push_back(root->data);
        inorder(root->right, temp);
    }

    void preorder(Node *root, vector<int> &temp)
    {
        if (root == NULL)
        {
            return;
        }
        temp.push_back(root->data);
        preorder(root->left, temp);
        preorder(root->right, temp);
    }

    void postorder(Node *root, vector<int> &temp)
    {
        if (root == NULL)
        {
            return;
        }
        postorder(root->left, temp);
        postorder(root->right, temp);
        temp.push_back(root->data);
    }

    vector<vector<int>> binaryTreeTraversal(Node *root)
    {
        vector<vector<int>> ans;
        vector<int> temp;
        inorder(root, temp);
        ans.push_back(temp);
        temp.clear();
        preorder(root, temp);
        ans.push_back(temp);
        temp.clear();
        postorder(root, temp);
        ans.push_back(temp);
        temp.clear();

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
    vector<vector<int>> traversal = sol.binaryTreeTraversal(root);
    cout << "Inorder Traversal: ";
    for (int i : traversal[0])
        cout << i << " ";
    cout << endl;
    cout << "Preorder Traversal: ";
    for (int i : traversal[1])
        cout << i << " ";
    cout << endl;
    cout << "Postorder Traversal: ";
    for (int i : traversal[2])
        cout << i << " ";
    cout << endl;
    return 0;
}