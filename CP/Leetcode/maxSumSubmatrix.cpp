#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

/* class Solution
{
public:
    int maxSumSubmatrix(vector<vector<int>> &matrix, int k)
    {
        if (matrix.empty() || matrix[0].empty())
            return 0;

        int m = matrix.size();    // Row
        int n = matrix[0].size(); // Column

        // Construct a sum query matrix
        vector<vector<int>> sum(m + 1, vector<int>(n + 1, 0));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + matrix[i][j];
            }
        }

        int ans = INT_MIN;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int p = i; p < m; p++)
                {
                    for (int q = j; q < n; q++)
                    {
                        int temp = sum[p + 1][q + 1] - sum[p + 1][j] - sum[i][q + 1] + sum[i][j];
                        if (temp == k) return k;
                        if (temp < k)
                        {
                            ans = max(ans, temp);
                        }
                    }
                }
            }
        }

        return ans;
    }
}; */

class Solution
{
public:
    int maxSumSubmatrix(vector<vector<int>> &matrix, int k)
    {
        if (matrix.empty())
            return 0;
        int row = matrix.size(), col = matrix[0].size(), res = INT_MIN;
        for (int l = 0; l < col; ++l)
        {
            vector<int> sums(row, 0);
            for (int r = l; r < col; ++r)
            {
                for (int i = 0; i < row; ++i)
                {
                    sums[i] += matrix[i][r];
                }

                // Find the max subarray no more than K
                set<int> accuSet;
                accuSet.insert(0);
                int curSum = 0, curMax = INT_MIN;
                for (int sum : sums)
                {
                    curSum += sum;
                    set<int>::iterator it = accuSet.lower_bound(curSum - k);
                    if (it != accuSet.end())
                        // Kanade's algorithm to find the max subarray no more than K
                        curMax = std::max(curMax, curSum - *it);
                    if (curMax == k)
                        return k;
                    accuSet.insert(curSum);
                }
                res = std::max(res, curMax);
            }
        }
        return res;
    }
};

int main()
{
    fastio;
    // code goes here
    Solution s;
    vector<vector<int>> matrix = {{2, 2, -1}};
    cout << s.maxSumSubmatrix(matrix, 3) << endl;

    return 0;
}