/**
 * xiebaoma
 * 2025-07-20
 */

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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode head(0);
        ListNode *ret = &head;
        while (list1 || list2)
        {
            if (!list1)
            {
                ret->next = list2;
                ret = ret->next;
                list2 = list2->next;
            }
            else if (!list2)
            {
                ret->next = list1;
                ret = ret->next;
                list1 = list1->next;
            }
            else
            {
                if (list1->val < list2->val)
                {
                    ret->next = list1;
                    ret = ret->next;
                    list1 = list1->next;
                }
                else
                {
                    ret->next = list2;
                    ret = ret->next;
                    list2 = list2->next;
                }
            }
        }
        return head.next;
    }
};