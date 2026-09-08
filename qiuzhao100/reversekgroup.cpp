
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };


class Solution {
public:

    void reversetwo(ListNode* start, ListNode* end){
        if(start==end){
            return;
        }
        ListNode* pre= end->next;
        ListNode* cur= start;
        ListNode* next=cur->next;
        while(cur!=end){
            cur->next=pre;
            pre= cur;
            cur=next;
            next=next->next;
        }
        cur->next=pre;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==nullptr){
            return head;
        }
        ListNode dummy(0);
        dummy.next=head;
        ListNode* pre= &dummy;
        while(true){
            ListNode* start= pre->next;
            ListNode* end= pre->next;
            if(end==nullptr){
                return dummy.next;
            }
            for(int i=1;i<k;i++){
                end=end->next;
                if(end==nullptr){
                    return dummy.next;
                }
            }
            reversetwo(start, end);
            pre->next= end;
            pre= start;
        }
        return dummy.next;
    }
};