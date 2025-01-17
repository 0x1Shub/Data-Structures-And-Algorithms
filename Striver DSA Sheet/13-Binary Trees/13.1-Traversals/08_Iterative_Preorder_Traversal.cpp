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
    vector<int> preOrderTraversal(Node *root)
    {
        vector<int> ans;
        if (root == NULL)
        {
            return ans;
        }

        stack<Node *> st;
        st.push(root);

        while (!st.empty())
        {
            root = st.top();
            st.pop();
            ans.push_back(root->data);

            if (root->right != NULL)
            {
                st.push(root->right);
            }
            if (root->left != NULL)
            {
                st.push(root->left);
            }
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
    vector<int> ans = sol.preOrderTraversal(root);
    for (auto x : ans)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}