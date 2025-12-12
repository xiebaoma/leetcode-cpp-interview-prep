/**
* Definition for singly-linked list.
 *
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
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy;
        ListNode* pre =&dummy;
        pre ->next =head;
        ListNode* node1=pre->next;
        if (!head) return head;
        ListNode* node2=node1->next;
        if (!node2) return head;
        ListNode* next =node2->next;
        while (node2)
        {
            pre->next=node2;
            node2->next=node1;
            node1->next=next;

            pre =node1;
            if (!pre->next) return dummy.next;
            node1 = pre->next;
            if (!node1->next) return dummy.next;
            node2=node1->next;
            next = node2->next;
        }
        return dummy.next;
    }
};