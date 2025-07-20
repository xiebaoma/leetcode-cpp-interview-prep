/**
 * xiebaoma
 * 2025-07-20
 */

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        if (head == nullptr)
        {
            return false;
        }
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast->next)
        {
            fast = fast->next->next;
            if (fast == nullptr)
            {
                return false;
            }
            slow = slow->next;
            if (fast == slow)
            {
                return true;
            }
        }
        return false;
    }
};