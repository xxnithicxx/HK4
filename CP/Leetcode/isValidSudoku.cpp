#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int> rows(9, 0), cols(9, 0), boxs(9, 0);

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '1';
                    int box = (i / 3) * 3 + j / 3; // Calculate the box number

                    if (rows[i] & (1 << num) || cols[j] & (1 << num) || boxs[box] & (1 << num)) {
                        return false;
                    }

                    rows[i] |= (1 << num);
                    cols[j] |= (1 << num);
                    boxs[box] |= (1 << num);
                }
            }
        }

        return true;
    }
};

int main()
{
    fastio;
    
    
    return 0;
}