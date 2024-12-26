#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void markRow(vector<vector<int>> &matrix, int n, int m, int i)
    {
        // set all non-zeros as -1 in col
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] != 0)
            {
                matrix[i][j] = -1;
            }
        }
    }

    void markCol(vector<vector<int>> &matrix, int n, int m, int j)
    {
        // set all non-zeros as -1 in rows
        for (int i = 0; i < n; i++)
        {
            if (matrix[i][j] != 0)
            {
                matrix[i][j] = -1;
            }
        }
    }

    vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m)
    {
        // set -1 for rows, cols which contain zero

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == 0)
                {
                    markRow(matrix, n, m, i);
                    markCol(matrix, n, m, j);
                }
            }
        }

        // make all -1 to 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == -1)
                {
                    matrix[i][j] = 0;
                }
            }
        }

        return matrix;
    }

    vector<vector<int>> optimal(vector<vector<int>> &matrix, int n, int m)
    {
        int col0 = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    if (j != 0)
                        matrix[0][j] = 0;
                    else
                        col0 = 0;
                }
            }
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                if (matrix[i][j] != 0)
                {
                    if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    {
                        matrix[i][j] = 0;
                    }
                }
            }
        }
        if (matrix[0][0] == 0)
        {
            for (int j = 0; j < m; j++)
            {
                matrix[0][j] = 0;
            }
        }
        if (col0 == 0)
        {
            for (int i = 0; i < n; i++)
            {
                matrix[i][0] = 0;
            }
        }

        return matrix;
    }
};

int main()
{
    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    int n = matrix.size();
    int m = matrix[0].size();
    Solution sol;

    vector<vector<int>> ans = sol.optimal(matrix, n, m);

    for (auto it : ans)
    {
        for (auto ele : it)
        {
            cout << ele << " ";
        }
        cout << endl;
    }
    return 0;
}