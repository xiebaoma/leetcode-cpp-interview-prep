/**
 *xiebaoma
 *2025-12-09
 */

#include <vector>
using namespace std;

struct ListNode {
         int val;
         ListNode *next;
         ListNode() : val(0), next(nullptr) {}
         ListNode(int x) : val(x), next(nullptr) {}
         ListNode(int x, ListNode *next) : val(x), next(next) {}
     };

class Solution {
public:
    ListNode* mergetwolist(ListNode* l1, ListNode* l2)
    {
        if (l1==l2)
        {
            return l1;
        }
        ListNode head(0);
        ListNode* pre= &head;
        while (l1 && l2)
        {
            if (l1->val > l2->val)
            {
                pre->next=l2;
                l2=l2->next;
            }else
            {
                pre->next=l1;
                l1=l1->next;
            }
            pre=pre->next;
        }
        while (l1)
        {
            pre->next=l1;
            l1=l1->next;
            pre=pre->next;
        }
        while (l2)
        {
            pre->next=l2;
            l2=l2->next;
            pre=pre->next;
        }
        return head.next;
    }

    ListNode* helpmerge(vector<ListNode*>& list, int l,int r)
    {
        int mid=l+(r-l)/2;
        if (l==r) return list[l];
        if (l==r-1) return mergetwolist(list[l],list[r]);
        ListNode* l1= helpmerge(list,l,mid);
        ListNode* l2= helpmerge(list,mid+1,r);
        return mergetwolist(l1,l2);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size()==0)
        {
            return nullptr;
        }
        int l=0;
        int r=lists.size()-1;
        return helpmerge(lists,l,r);
    }
};