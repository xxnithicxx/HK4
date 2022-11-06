#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

class Solution
{
public:
    int nthSuperUglyNumber(int n, vector<int> &primes)
    {
        int k = primes.size();
        vector<int> dp(n, INT_MAX);
        vector<int> idx(k, 0);
        dp[0] = 1;

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < k; j++)
            {
                long long val = (long long) dp[idx[j]] * (long long) primes[j];
                dp[i] = min((long long) dp[i], val);
            }

            for (int j = 0; j < k; j++)
            {
                long long val = (long long) dp[idx[j]] * (long long) primes[j];
                if ((long long) dp[i] == val)
                {
                    idx[j]++;
                }
            }
        }

        return dp[n - 1];
    }
};

int main()
{
    fastio;
    Solution s;
    vector<int> primes = {2, 7, 13, 19};
    cout << s.nthSuperUglyNumber(12, primes) << endl;

    return 0;
}