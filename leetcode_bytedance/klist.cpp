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
    void reverse(ListNode* head, ListNode* end){
        ListNode* nextnode= end->next;
        ListNode* pre =nullptr;
        ListNode* cur =head;
        ListNode* next =head->next;
        while(cur!=end){
            cur->next=pre;
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
        ListNode* first=head;
        ListNode* second=head;
        while(second){
            int i=1;
            while(second && i<k){
                second=second->next;
                i++;
            }
            if(i!=k || !second){
                break;
            }
            reverse(first,second);
            pre->next=second;
            pre=first;
            first=pre->next;
            second=pre->next;
        }
        return dummy.next;
    }
};