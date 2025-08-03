/**
 * xiebaoma
 * 2025-08-03
 */

#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode* mergetwolist(ListNode* l1, ListNode* l2)
    {
        ListNode dummy(0);
        ListNode* node=&dummy;
        while(l1 && l2)
        {
            if(l1->val > l2->val)
            {
                node->next= l2;
                l2=l2->next;
            }
            else
            {
                node->next=l1;
                l1=l1->next;
            }
            node=node->next;
        }
        node->next= l1? l1:l2;
        return dummy.next;
    }
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        int n = lists.size();
        ListNode dummy(0);
        ListNode* node= &dummy;
        if(lists.size()==0)
        {
            return dummy.next;
        }
        node->next= lists[0];
        for(int i=1;i<n;i++)
        {
            node->next= mergetwolist(node->next,lists[i]);
        }
        return dummy.next;
    }
};