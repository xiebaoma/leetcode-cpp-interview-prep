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
    ListNode *reverse(ListNode *start, ListNode *end)
    {
        ListNode *prev = end->next;
        ListNode *curr = start;
        while (prev != end)
        {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return end;
    }

    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (!head || k == 1)
            return head;

        ListNode dummy(0);
        dummy.next = head;
        ListNode *pre = &dummy;
        ListNode *curr = head;

        while (curr)
        {
            ListNode *tail = pre;
            // 检查剩余节点是否够 k 个
            for (int i = 0; i < k; ++i)
            {
                tail = tail->next;
                if (!tail)
                    return dummy.next;
            }
            ListNode *next = tail->next;
            ListNode *start = curr;

            reverse(start, tail); // 原地反转

            pre->next = tail;
            start->next = next;

            pre = start;
            curr = next;
        }
        return dummy.next;
    }
};
