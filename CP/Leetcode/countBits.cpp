#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result(n + 1, 0);

        for (int i = 0; i <= n; i++) {
            result[i] = result[i >> 1] + (i&1);
        }

        return result;
    }
};

int main()
{
    fastio;

    int n;
    cin >> n;
    vector<int> result = Solution().countBits(n);
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";

    return 0;
}