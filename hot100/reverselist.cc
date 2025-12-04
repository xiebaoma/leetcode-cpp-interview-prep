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

struct ListNode {
         int val;
         ListNode *next;
         ListNode() : val(0), next(nullptr) {}
         ListNode(int x) : val(x), next(nullptr) {}
         ListNode(int x, ListNode *next) : val(x), next(next) {}
     };

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = nullptr;
        if (head==nullptr)
        {
            return head;
        }
        ListNode* next = head->next;
        ListNode* cur = head;
        //0<-0->0
        while (next)
        {
            cur->next=pre;
            pre = cur;
            cur=next;
            next=next->next;
        }
        cur->next =pre;
        return cur;
    }
};