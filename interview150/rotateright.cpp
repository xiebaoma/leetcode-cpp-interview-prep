/**
 * Definition for singly-linked list.
 *
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

    ListNode *rotateRight(ListNode *head, int k)
    {
        int count = listcount(head);
        if(count==0) return head;
        k %= count;
        if(k==0) return head;
        int n = count - k;
        ListNode dummy(0);
        dummy.next = head;
        ListNode *pre = &dummy;
        for (int i = 1; i <= n; i++)
        {
            pre = pre->next;
        }
        ListNode *newhead = pre->next;
        pre->next = nullptr;
        ListNode *node = newhead;
        while (node->next)
        {
            node = node->next;
        }
        node->next = head;
        return newhead;
    }
};