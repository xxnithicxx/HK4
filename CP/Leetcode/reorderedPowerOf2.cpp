#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

class Solution
{
public:
    // bool reorderedPowerOf2(int n)
    // {
    //     string s = to_string(n);
    //     sort(s.begin(), s.end());
    //     do
    //     {
    //         if (s[0] == '0')
    //             continue;
    //         // Check is s is a power of 2
    //         int power = 1;
    //         for (int i = 0; i < 31; i++)
    //         {
    //             power = pow(2, i);
    //             if (power == stoi(s))
    //                 return true;
    //         }
    //     } while (next_permutation(s.begin(), s.end()));
    //     return false;
    // }

    bool reorderedPowerOf2(int n) 
    {
        // Using counting numbers of digits
        vector<int> count = countDigits(n);

        int power = 1;
        for (int i = 0; i < 30; i++)
        {
            // Compare count of digits
            vector<int> count2 = countDigits(power);
            if(count2.size() != count.size())
                continue;
            if (count2.size() > count.size())
                break;
            if (count == count2)
                return true;
            power <<= 1;
        }

        return false;
    }

    vector<int> countDigits(int n)
    {
        vector<int> count(10, 0);
        while (n)
        {
            count[n % 10]++;
            n /= 10;
        }
        return count;
    }
};

int main()
{
    fastio;
    // code goes here

    // Test case
    Solution s;
    cout << boolalpha << s.reorderedPowerOf2(1) << endl;

    return 0;
}