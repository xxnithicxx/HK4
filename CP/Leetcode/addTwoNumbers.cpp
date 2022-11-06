#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *temp1 = l1;
        ListNode *temp2 = l2;
        ListNode *ans = nullptr;
        bool modNum = false;
        while (temp1 != nullptr && temp2 != nullptr)
        {
            int sum = temp1->val + temp2->val + modNum;
            modNum = false;
            if (sum > 9)
            {
                sum = sum % 10;
                modNum = true;
            }

            if (ans == nullptr)
            {
                ans = new ListNode(sum);
                temp1 = temp1->next;
                temp2 = temp2->next;
                continue;
            }

            ListNode *temp = ans;
            while (temp->next != nullptr)
                temp = temp->next;

            temp->next = new ListNode(sum);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        while (temp1 != nullptr)
        {
            int sum = temp1->val + modNum;
            modNum = false;
            if (sum > 9)
            {
                sum = sum % 10;
                modNum = true;
            }

            ListNode *temp = ans;
            while (temp->next != nullptr)
                temp = temp->next;

            temp->next = new ListNode(sum);
            temp1 = temp1->next;
        }

        while (temp2 != nullptr)
        {
            int sum = temp2->val + modNum;
            modNum = false;
            if (sum > 9)
            {
                sum = sum % 10;
                modNum = true;
            }

            ListNode *temp = ans;
            while (temp->next != nullptr)
                temp = temp->next;

            temp->next = new ListNode(sum);
            temp2 = temp2->next;
        }

        if (modNum)
        {
            ListNode *temp = ans;
            while (temp->next != nullptr)
                temp = temp->next;

            temp->next = new ListNode(modNum);
        }

        return ans;
    }
};

int main()
{
    fastio;
    // code goes here

    ListNode *l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
    ListNode *l2 = new ListNode(5, new ListNode(6, new ListNode(4)));

    Solution s;
    ListNode *ans = s.addTwoNumbers(l1, l2);
    while (ans != nullptr)
    {
        cout << ans->val << " ";
        ans = ans->next;
    }

    return 0;
}