#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

class Solution {
public:
    void bfs(vector<vector<bool>> &mat, int i, int j)
    {
        // If the entry is zero, then return
        if (!mat[i][j])
            return;

        // Mark the entry is not zero, call the function recursively for all the adjacent entries
        mat[i][j] = false;
        if (i > 0)
            bfs(mat, i - 1, j);
        if (i < mat.size() - 1)
            bfs(mat, i + 1, j);
        if (j > 0)
            bfs(mat, i, j - 1);
        if (j < mat[0].size() - 1)
            bfs(mat, i, j + 1);
        
        return;
    }

    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty())
            return 0;
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<bool>> map(rows, vector<bool>(cols, false));

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (grid[i][j] == '1')
                {
                    map[i][j] = true;
                }
            }
        }

        int count = 0;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (map[i][j] == true)
                {
                    count++;
                    bfs(map, i, j);
                }
            }
        }
        return count;
    }
};

int main()
{
    fastio;
    // code goes here
    Solution s;
    vector<vector<char>> grid = {
        {'1','1','0','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','1','1'}
    };

    cout << s.numIslands(grid) << endl;

    return 0;
}