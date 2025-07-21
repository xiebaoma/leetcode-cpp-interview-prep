/**
 * xiebaoma
 * 2025-07-21
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
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode dummy(0);
        ListNode *pre = &dummy;
        while (head)
        {
            int val = head->val;
            int count = 0;
            while (head && head->val == val)
            {
                head = head->next;
                count++;
            }
            if (count == 1)
            {
                pre->next = new ListNode(val);
                pre = pre->next;
            }
        }
        return dummy.next;
    }
};