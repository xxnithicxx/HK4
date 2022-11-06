#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

class Solution
{
public:
    int maxSumSubmatrix(vector<vector<int>> &matrix, pair<int, int> a, pair<int, int> b)
    {
        if (matrix.empty() || matrix[0].empty())
            return 0;

        int m = matrix.size();    // Row
        int n = matrix[0].size(); // Column

        // Construct a sum query matrix
        vector<vector<int>> sum(m, vector<int>(n, 0));
        sum[0][0] = matrix[0][0];

        // Check the sum of the first row and first column
        for (int i = 1; i < m; i++)
        {
            sum[i][0] = sum[i - 1][0] + matrix[i][0];
        }
        for (int i = 1; i < n; i++)
        {
            sum[0][i] = sum[0][i - 1] + matrix[0][i];
        }

        // Compute the sum of the rest of the matrix
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + matrix[i][j];
            }
        }

        // Find the sum of matrix from (a.first, a.second) to (b.first, b.second)
        int temp1, temp2, temp3;
        if (a.first - 1 < 0)
        {
            temp1 = 0;
            temp3 = 0;
        }
        else
        {
            temp1 = sum[a.first - 1][b.second];
        }
        if (a.second - 1 < 0)
        {
            temp2 = 0;
            temp3 = 0;
        }
        else
        {
            temp2 = sum[b.first][a.second - 1];
        }
        if (a.first - 1 < 0 || a.second - 1 < 0)
        {
            temp3 = 0;
        }
        else
        {
            temp3 = sum[a.first - 1][a.second - 1];
        }

        int ansSum = sum[b.first][b.second] - temp1 - temp2 + temp3;
        return ansSum;
    }
};

int main()
{
    fastio;
    
    return 0;
}