#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

/* class Solution
{
public:
    vector<vector<int>>
    diagonalSort(vector<vector<int>> &mat)
    {
        if (mat.empty())
            return mat;

        int rows = mat.size();
        int cols = mat[0].size();

        for (int i = 0; i < cols; i++)
        {
            vector<int> sortArr;
            for (int j = i; j < rows + i; j++)
            {
                sortArr.push_back(mat[j - i][j]);
                if (j == cols - 1)
                    break;
            }
            sort(sortArr.begin(), sortArr.end());

            for (int j = i; j < rows + i; j++)
            {
                mat[j - i][j] = sortArr[j - i];
                if (j == cols - 1)
                    break;
            }
        }

        for (int i = 0; i < rows; i++)
        {
            vector<int> sortArr;
            for (int j = i; j < cols + i; j++)
            {
                sortArr.push_back(mat[j][j - i]);
                if (j == rows - 1)
                    break;
            }
            sort(sortArr.begin(), sortArr.end());

            for (int j = i; j < cols + i; j++)
            {
                mat[j][j - i] = sortArr[j - i];
                if (j == rows - 1)
                    break;
            }
        }

        return mat;
    }
}; */

class Solution
{
public:
    vector<vector<int>> diagonalSort(vector<vector<int>> &mat)
    {
        unordered_map<int, vector<int>> mp;

        int rows = mat.size(), cols = mat[0].size();

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                mp[i - j].push_back(mat[i][j]);
            }
        }
        for (auto it = mp.begin(); it != mp.end(); it++)
        {
            sort(it->second.begin(), it->second.end());
        }

        for (int i = rows - 1; i >= 0; i--)
        {
            for (int j = cols - 1; j >= 0; j--)
            {
                mat[i][j] = mp[i - j].back();
                mp[i - j].pop_back();
            }
        }

        return mat;
    }
};

int main()
{
    fastio;
    // code goes here

    Solution s;
    vector<vector<int>> mat = {{3, 3, 1, 1}, {2, 2, 1, 2}, {1, 1, 1, 2}};
    for (auto row : mat)
    {
        for (auto entry : row)
        {
            cout << entry << " ";
        }
        cout << endl;
    }
    cout << endl;

    s.diagonalSort(mat);

    for (auto row : mat)
    {
        for (auto entry : row)
        {
            cout << entry << " ";
        }
        cout << endl;
    }

    return 0;
}