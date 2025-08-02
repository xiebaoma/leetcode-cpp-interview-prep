/**
 * xiebaoma
 * 2025-08-02
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
    ListNode *getmid(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head->next;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *node = slow->next;
        slow->next = nullptr;
        return node;
    }
    ListNode *merge(ListNode *first, ListNode *second)
    {
        ListNode dummy(0);
        ListNode *node = &dummy;
        while (first && second)
        {
            if (first->val < second->val)
            {
                node->next = first;
                first = first->next;
            }
            else
            {
                node->next = second;
                second = second->next;
            }
            node = node->next;
        }
        node->next = first ? first : second;
        return dummy.next;
    }
    ListNode *sortList(ListNode *head)
    {
        if(!head || !head->next){
            return head;
        }
        ListNode *first = head;
        ListNode *second = getmid(head);
        first = sortList(first);
        second = sortList(second);
        first = merge(first, second);
        return first;
    }
};