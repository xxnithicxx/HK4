#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0)
            return "";
        if (strs.size() == 1)
            return strs[0];

        string ans = strs[0];
        for (int i = 1; i < strs.size(); i++)
        {
            int j = 0;
            while (j < ans.size() && j < strs[i].size() && ans[j] == strs[i][j])
                j++;
            ans = ans.substr(0, j);
        }
        return ans;
    }
};

int main()
{
    fastio;
    // code goes here

    vector<string> strs = {"flower", "flow", "flight"};
    Solution s;
    cout << s.longestCommonPrefix(strs) << endl;

    return 0;
}