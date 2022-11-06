#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0 || (x % 10 == 0 && x != 0))
        {
            return false;
        }

        int half = 0;
        while (x > half)
        {
            half = half * 10 + x % 10;
            x /= 10;
        }

        return x == half || x == half / 10;
    }
};

int main()
{
    fastio;
    // code goes here

    Solution sl;
    cout << boolalpha << sl.isPalindrome(12321);

    return 0;
}