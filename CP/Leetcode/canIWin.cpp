#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

class Solution
{
public:
    int dp[1 << 20] = {0};

    bool dfs(int state, int maxChoosableInteger, int desiredTotal)
    {
        if (dp[state] != 0)
            return dp[state] == 1;

        for (int i = 0; i < maxChoosableInteger; i++)
        {
            int cur = 1 << i;
            if ((state & cur) == 0)
            {
                if (i + 1 >= desiredTotal || !dfs(state | cur, maxChoosableInteger, desiredTotal - (i + 1)))
                {
                    dp[state] = 1;
                    return true;
                }
            }
        }

        dp[state] = -1;
        return false;
    }

    bool canIWin(int maxChoosableInteger, int desiredTotal)
    {
        if (maxChoosableInteger < desiredTotal)
            return true;

        int sum = maxChoosableInteger * (maxChoosableInteger + 1) / 2;

        // If the total sum is less than or equal to the desired total, then there no way to win.
        if (sum < desiredTotal)
            return false;

        // If the total sum is equal to the desired total, then there is only one way to win if the total number of entry is odd.
        if (sum == desiredTotal)
            return maxChoosableInteger % 2;

        return dfs(0, maxChoosableInteger, desiredTotal);
    }
};

int main()
{
    fastio;

    return 0;
}