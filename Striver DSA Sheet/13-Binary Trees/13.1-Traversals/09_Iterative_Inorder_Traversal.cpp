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
    vector<int> inorderTraversal(Node *root)
    {
        vector<int> ans;
        stack<Node *> st;
        Node *curr = root;

        while (curr != NULL || !st.empty())
        {
            while (curr != NULL)
            {
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top();
            st.pop();
            ans.push_back(curr->data);
            curr = curr->right;
        }

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
