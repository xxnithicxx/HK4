#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

class Solution
{
public:
    int kadane(vector<int> &array)
    {
        int maxTillNow = INT_MIN;
        int curMax = 0;
        for (int entry : array)
        {
            curMax = max(curMax + entry, entry);
            maxTillNow = max(maxTillNow, curMax);
        }
        return maxTillNow;
    }

    int maxSubmatrix(vector<vector<int>> &matrix)
    {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return 0;

        int row = matrix.size(), col = matrix[0].size();
        vector<vector<int>> preMatrix(row, vector<int>(col + 1, 0));

        // Calculate prefix array base on row and store in prefix matrix
        for (int i = 0; i < col; i++)
        {
            for (int j = 0; j < row; j++)
            {
                preMatrix[j][i + 1] = preMatrix[j][i] + matrix[j][i];
            }
        }

        int maxSum = INT_MIN;
        for (int left = 0; left < col; left++)
        {
            for (int right = left; right < col; right++)
            {
                vector<int> currArray(row, 0);
                for (int i = 0; i < row; i++)
                {
                    currArray[i] = preMatrix[i][right + 1] - preMatrix[i][left];
                }

                int currSum = kadane(currArray);
                maxSum = max(maxSum, currSum);
            }
        }

        return maxSum;
    }
};

int main()
{
    fastio;
    // code goes here
    Solution s;
    vector<vector<int>> matrix = {{0, -2, -7, 0},
                                  {9, 2, -6, 2},
                                  {-4, 1, -4, 1},
                                  {-1, 8, 0, -2}};
    cout << s.maxSubmatrix(matrix) << endl;

    return 0;
}