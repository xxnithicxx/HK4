#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // Traverse the matrix in main diagonal order
        int size = matrix.size();

        for (int i = 0; i < size; i++) {
            for (int j = i; j < size; j++) {
                if (i < j) {
                    swap(matrix[i][j], matrix[j][i]);
                }
            }
        }

        // Traverse the matrix in the midline order
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size / 2; j++) {
                swap(matrix[i][j], matrix[i][size - j - 1]);
            }
        }
    }
};

int main()
{
    fastio;

    Solution s;
    int n;
    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = i * n + j;
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    s.rotate(matrix);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }


    return 0;
}