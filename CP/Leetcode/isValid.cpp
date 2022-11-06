#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        if (s.length() == 0)
            return true;

        stack<char> sc;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '[' || s[i] == '(' || s[i] == '{')
                sc.push(s[i]);

            if (s[i] == ']' || s[i] == ')' || s[i] == '}')
            {
                if (sc.empty())
                    return false;
                // ([{}(){}])
                switch (sc.top())
                {
                case '[':
                    if (s[i] != ']')
                        return false;
                    break;
                case '{':
                    if (s[i] != '}')
                        return false;
                    break;
                case '(':
                    if (s[i] != ')')
                        return false;
                    break;
                default:
                    break;
                }

                sc.pop();
            }
        }

        return sc.empty();
    }
};

int main()
{
    fastio;
    // code goes here
    Solution s;
    cout << boolalpha << s.isValid("(]");
    return 0;
}