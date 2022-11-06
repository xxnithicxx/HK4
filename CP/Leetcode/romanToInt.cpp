#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl '\n'

using namespace std;

class Solution
{
public:
    int charToInt(char s)
    {
        int roman[7] = {1, 5, 10, 50, 100, 500, 1000};
        char symbol[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};

        for (int i = 0; i < 7; i++)
        {
            if (symbol[i] == s)
            {
                return roman[i];
            }
        }

        return 0;
    }

    int romcmp(char c1, char c2)
    {
        char symbol[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};

        int index1 = -1, index2 = -1;
        for (int i = 0; i < 7; i++)
        {
            if (c1 == symbol[i])
                index1 = i;

            if (c2 == symbol[i])
                index2 = i;
        }

        if (c1 < 0 || c2 < 0)
            return 1;

        if (index1 < index2)
            return -1;
        else if (index1 > index2)
            return 1;
        else
            return 0;
    }

    int romanToInt(string s)
    {
        int ans = 0;
        stack<char> stc;

        for (int i = 0; i < s.size(); i++)
        {
            stc.push(s[i]);
        }

        char temp = 'S';
        int sum = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (romcmp(stc.top(), temp) >= 0)
                sum += charToInt(stc.top());
            else
                sum -= charToInt(stc.top());

            temp = stc.top();
            stc.pop();
        }

        return sum;
    }
};

int main()
{
    fastio;
    // code goes here

    Solution sc;
    cout << sc.romanToInt("DCCCXLV");

    return 0;
}