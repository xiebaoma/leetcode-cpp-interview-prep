/**
* xiebaoma
 * 2025-12-08
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
    void reversetwonode(ListNode* head,ListNode* end)
    {
        ListNode* nextnode = end->next;
        ListNode* pre=nullptr;
        ListNode* cur=head;
        ListNode* next = head->next;
        while (cur!=end)
        {
            cur->next = pre;
            pre=cur;
            cur=next;
            next=next->next;
        }
        cur->next=pre;
        head->next=nextnode;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy;
        ListNode* pre =&dummy;
        ListNode* slow=head;
        ListNode* fast=head;
        while (fast)
        {
            for (int i=1;i<k;i++)
            {
                if (fast->next==nullptr) return dummy.next;
                fast=fast->next;
            }
            reversetwonode(slow,fast);
            pre->next = fast;
            pre =slow;
            slow = pre->next;
            fast = pre->next;
        }
        return dummy.next;
    }
};