#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node *left;
    Node *right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
private:
    void inorder(Node *node, vector<int> &arr)
    {
        if (!node)
        {
            return;
        }
        inorder(node->left, arr);
        arr.push_back(node->val);
        inorder(node->right, arr);
        return;
    }

public:
    pair<int, int> findKth(Node *node, int k)
    {
        vector<int> arr;
        inorder(node, arr);
        int kLargest = arr[arr.size() - k];
        int kSmallest = arr[k - 1];
        return make_pair(kSmallest, kLargest);
    }
};

class Optimal
{
private:
    void reverseInorder(Node *node, int &counter, int k, int &kLargest)
    {
        if (!node || counter >= k)
            return;
        reverseInorder(node->right, counter, k, kLargest);
        counter++;
        if (counter == k)
        {
            kLargest = node->val;
            return;
        }
        reverseInorder(node->left, counter, k, kLargest);
    }

    void inorder(Node *node, int &counter, int k, int &kSmallest)
    {
        if (!node || counter >= k)
            return;
        inorder(node->left, counter, k, kSmallest);
        counter++;
        if (counter == k)
        {
            kSmallest = node->val;
            return;
        }
        inorder(node->right, counter, k, kSmallest);
    }

public:
    pair<int, int> findKth(Node *root, int k)
    {
        int kSmallest = INT_MIN, kLargest = INT_MIN;
        int counter = 0;
        inorder(root, counter, k, kSmallest);
        counter = 0;
        reverseInorder(root, counter, k, kLargest);
        return make_pair(kSmallest, kLargest);
    }
};

void printInOrder(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    printInOrder(root->left);
    cout << root->val << " ";
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

    Optimal opt;
    int k = 3;
    cout << "k: " << k << endl;
    pair<int, int> kthElements = opt.findKth(root, k);

    cout << "Kth smallest element: " << kthElements.first << endl;
    cout << "Kth largest element: " << kthElements.second << endl;

    return 0;
}
