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

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode head;
        ListNode* pre= &head;
        while (list1 && list2)
        {
            if (list1->val > list2->val)
            {
                pre->next = list2;
                list2 = list2->next;
            }else
            {
                pre->next = list1;
                list1= list1->next;
            }
            pre= pre->next;
        }
        while (list1)
        {
            pre->next=list1;
            list1=list1->next;
            pre =pre->next;
        }
        while (list2)
        {
            pre->next=list2;
            list2=list2->next;
            pre=pre->next;
        }
        return head.next;
    }

    ListNode* sortList(ListNode* head) {
        if (head==nullptr || head->next==nullptr) return head;
        ListNode* slow =head;
        ListNode* fast =head->next;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast =fast->next->next;
        }
        ListNode* mid=slow->next;
        slow->next=nullptr;
        ListNode* l1=sortList(head);
        ListNode* l2=sortList(mid);
        ListNode* res= mergeTwoLists(l1,l2);
        return res;
    }
};