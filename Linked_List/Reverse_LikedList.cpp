#include <bits/stdc++.h>;
using namespace std;

// Reverse a linked list
 
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {

        // step 1
        ListNode *prev_p = NULL;
        ListNode *current_p = head;
        ListNode *next_p;

        // step 2
        while (current_p)
        {
            next_p = next_p->next;
            current_p->next = prev_p;

            prev_p = current_p;
            current_p = next_p;
        }

        // step 3
        head = prev_p;
        return head;
    }
};





main()
{
    return 0;
}