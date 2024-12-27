// Variation 1: Given row number r and column number c. Print the element at position (r, c) in Pascal’s triangle.

// Variation 2: Given the row number n. Print the n-th row of Pascal’s triangle.

// Variation 3: Given the number of rows n. Print the first n rows of Pascal’s triangle.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int nCr(int n, int r)
    {
        long long res = 1;
        for (int i = 0; i < r; i++)
        {
            res = res * (n - i);
            res = res / (i + 1);
        }
        return res;
    }

    int variation1(int row, int col)
    {
        int element = nCr(row - 1, col - 1);
        return element;
    }

    void variation2(int row)
    {
        for (int col = 1; col <= row; col++)
        {
            cout << nCr(row - 1, col - 1) << " ";
        }
        cout << endl;
    }

    vector<vector<int>> variation3(int n)
    {
        vector<vector<int>> ans;

        for (int row = 1; row <= n; row++)
        {
            vector<int> tempList;
            for (int col = 1; col <= row; col++)
            {
                tempList.push_back(nCr(row - 1, col - 1));
            }
            ans.push_back(tempList);
        }
        return ans;
    }
};

class Optimal
{
public:
    vector<int> generateRow(int row)
    {
        long long ans = 1;
        vector<int> ansRow;
        ansRow.push_back(1);
        for (int col = 1; col < row; col++)
        {
            ans = ans * (row - col);
            ans = ans / col;
            ansRow.push_back(ans);
        }
        return ansRow;
    }

    vector<vector<int>> pascalTriangle(int n)
    {
        vector<vector<int>> ans;
        for (int row = 1; row <= n; row++)
        {
            ans.push_back(generateRow(row));
        }
        return ans;
    }
};

int main()
{
    int row = 5;
    int col = 3;
    Solution sol;
    cout << "The element at position (r, c) is: " << sol.variation1(row, col) << endl;
    sol.variation2(row);

    vector<vector<int>> ans = sol.variation3(row);
    for (auto it : ans)
    {
        for (auto x : it)
        {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}