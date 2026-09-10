
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
        dummy.next=head;
        ListNode* pre= &dummy;
        while(true){
            if(pre==nullptr || pre->next==nullptr){
                return dummy.next;
            }
            ListNode* node1= pre->next;
            if(node1->next==nullptr){
                return dummy.next;
            }
            ListNode* node2= node1->next;
            ListNode* next= node2->next;
            pre->next= node2;
            node2->next=node1;
            node1->next=next;
            pre=node1;
        }
        return dummy.next;
    }
};