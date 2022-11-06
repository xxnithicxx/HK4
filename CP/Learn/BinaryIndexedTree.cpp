#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

class Solution
{
private:
    vector<int> BIT;

    int sum(int a)
    {
        int sum = 0;
        while (a >= 1)
        {
            sum += BIT[a];
            a -= (a & -a); // a & -a is bitwise operation to get the lowest 1s bit of a (which mean the largest power of two that a divides)
            // a += 1 << __builtin_ctz(a); // __builtin_ctz is the number of trailing zeros of a
        }
        return sum;
    }

    void buildIndexTree(vector<int> &arr)
    {
        BIT.assign(arr.size() + 1, 0);
        for (int i = 0; i < arr.size(); i++)
            BIT[i + 1] = arr[i];

        for (int j = 1; j < BIT.size(); j++)
        {
            int parent = j + (j & -j);
            if (parent < BIT.size())
                BIT[parent] += BIT[j];
        }
    }

public:
    Solution(vector<int> &arr)
    {
        buildIndexTree(arr);
    }

    int sumOfSubArray(int l, int r)
    {
        return sum(r + 1) - sum(l);
    }

    void add(int index, int val)
    {
        index++;
        while (index <= BIT.size())
        {
            BIT[index] += val;
            index += (index & -index);
        }
    }
};

int main()
{
    fastio;
    // code goes here
    vector<int> qs = {1, 3, 4, 8, 6, 1, 4, 2};
    Solution s(qs);
    s.add(1, 2);
    cout << s.sumOfSubArray(4, 5) << endl;

    return 0;
}