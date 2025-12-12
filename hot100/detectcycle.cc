/**
* Definition for singly-linked list.
 *
 */

#include <unordered_set>
using namespace std;

struct ListNode {
         int val;
         ListNode *next;
         ListNode(int x) : val(x), next(NULL) {}
     };

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast= fast->next->next;
            if (slow ==fast)
            {
                ListNode* index1=head;
                ListNode* index2=slow;
                while (index1!=index2)
                {
                    index1=index1->next;
                    index2=index2->next;
                }
                return index1;
            }
        }
        return nullptr;
    }
};