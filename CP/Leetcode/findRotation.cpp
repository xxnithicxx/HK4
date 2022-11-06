#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

class Solution
{
public:
    bool findRotation(vector<vector<int>> &mat, vector<vector<int>> &target)
    {
        bool rotation[4] = {true, true, true, true};
        int n = mat.size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] != target[i][j])
                    rotation[0] = false;

                if (mat[i][j] != target[j][n - i - 1])
                    rotation[1] = false;

                if (mat[i][j] != target[n - i - 1][n - j - 1])
                    rotation[2] = false;

                if (mat[i][j] != target[n - j - 1][i])
                    rotation[3] = false;
            }
        }

        return rotation[0] || rotation[1] || rotation[2] || rotation[3];
    }
};

int main()
{
    fastio;

    Solution s;
    vector<vector<int>> matrix(3, vector<int>(3));
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            matrix[i][j] = i * 3 + j;
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    vector<vector<int>> target(3, vector<int>(3));
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            target[i][j] = i * 3 + j;
            cout << target[i][j] << " ";
        }
        cout << endl;
    }

    cout << boolalpha << s.findRotation(matrix, target) << endl;

    return 0;
}