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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode head;
        ListNode* pre = &head;
        int c= 0;
        while (l1 || l2)
        {
            int num1 = l1? l1->val:0;
            int num2 = l2? l2->val:0;
            int val = (c+ num1+num2)%10;
            c= (c+num1+num2)/10;

            ListNode* node = new ListNode(val);
            pre->next =node;
            pre=pre->next;

            if (l1) l1=l1->next;
            if (l2) l2=l2->next;
        }
        if (c==1)
        {
            ListNode* node = new ListNode(1);
            pre->next =node;
        }
        return head.next;
    }
};