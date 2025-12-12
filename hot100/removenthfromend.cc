/**
 * xiebaoma
 * 2025-12-12
 */

struct ListNode {
         int val;
         ListNode *next;
         ListNode() : val(0), next(nullptr) {}
         ListNode(int x) : val(x), next(nullptr) {}
         ListNode(int x, ListNode *next) : val(x), next(next) {}
     };

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count =0;
        ListNode dummy;
        ListNode* pre= &dummy;
        pre->next = head;
        while (pre->next)
        {
            pre = pre->next;
            count++;
        }
        int nth = count - n;
        pre =&dummy;
        while (nth>0)
        {
            pre =pre->next;
            nth--;
        }
        ListNode* next=pre->next;
        pre->next = next->next;
        delete next;
        return dummy.next;
    }
};