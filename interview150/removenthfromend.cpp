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
    int listcount(ListNode *head)
    {
        int count = 0;
        while (head)
        {
            count++;
            head = head->next;
        }
        return count;
    }

    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode dummy(0);
        dummy.next = head;
        int sum = listcount(head);
        n = sum - n + 1;
        ListNode *pre = &dummy;
        for (int i = 1; i <= n - 1; i++)
        {
            pre = pre->next;
        }
        if (pre->next)
        {
            pre->next = pre->next->next;
        }
        return dummy.next;
    }
};