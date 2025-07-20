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
    ListNode *reverse(ListNode *mleft, ListNode *mright)
    {
        ListNode *left = mleft;
        ListNode *right = mright;
        ListNode *pre = right->next;
        ListNode *next = left->next;
        while (left != right)
        {
            left->next = pre;
            pre = left;
            left = next;
            if (next)
                next = next->next;
        }
        left->next = pre;
        return right;
    }

    ListNode *reverseBetween(ListNode *head, int left, int right)
    {

        int count = 1;
        ListNode *leftnode;
        ListNode *rightnode;
        ListNode dummy(0);
        ListNode *pre = &dummy;
        ListNode *node = &dummy;
        dummy.next = head;
        while (count < left)
        {
            node = node->next;
            count++;
        }
        pre = node;
        leftnode = pre->next;
        while (count < right)
        {
            node = node->next;
            count++;
        }
        rightnode = node->next;
        pre->next = reverse(leftnode, rightnode);
        return dummy.next;
    }
};