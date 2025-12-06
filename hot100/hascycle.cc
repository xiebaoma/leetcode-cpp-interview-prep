/**
 * xiebaoma
 * 2025-12-06
 */

struct ListNode {
         int val;
         ListNode *next;
         ListNode(int x) : val(x), next(NULL) {}
     };
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head==nullptr)
        {
            return false;
        }
        ListNode* fast=head;
        ListNode* slow=head;
        while (fast)
        {
            fast=fast->next;
            if (fast)
            {
                fast=fast->next;
            }else
            {
                return false;
            }
            if (fast==slow)
            {
                return true;
            }
            slow = slow ->next;
        }
        return false;
    }
};