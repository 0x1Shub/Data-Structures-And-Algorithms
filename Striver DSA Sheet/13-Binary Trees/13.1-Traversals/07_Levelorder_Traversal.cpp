// Breadth First Search

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
    vector<vector<int>> levelorderTraversal(Node *root)
    {
        vector<vector<int>> ans;
        if (root == NULL)
        {
            return ans;
        }
        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            int size = q.size();
            vector<int> level;

            for (int i = 0; i < size; i++)
            {
                Node *temp = q.front();
                q.pop();
                level.push_back(temp->data);

                if (temp->left != NULL)
                {
                    q.push(temp->left);
                }
                if (temp->right != NULL)
                {
                    q.push(temp->right);
                }
            }

            ans.push_back(level);
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
    vector<vector<int>> ans = sol.levelorderTraversal(root);

    for (auto x : ans)
    {
        cout << "[";
        for (auto it : x)
        {
            cout << it << " ";
        }
        cout << "]";
    }
    cout << endl;

    return 0;
}