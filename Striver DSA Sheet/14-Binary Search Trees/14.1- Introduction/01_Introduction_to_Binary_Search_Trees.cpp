// Check the arr is Binary Search Tree It is Inorder traversal

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isBinarySearchTree(vector<int> &arr)
    {
        for (int i = 0; i < arr.size() - 1; i++)
        {
            if (arr[i + 1] <= arr[i])
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    vector<int> arr = {8, 14, 45, 64, 100};
    Solution sol;
    if (sol.isBinarySearchTree(arr))
    {
        cout << "It is Binary Search Tree" << endl;
    }
    else
    {
        cout << "It is not a Binary Search Tree" << endl;
    }
    return 0;
}