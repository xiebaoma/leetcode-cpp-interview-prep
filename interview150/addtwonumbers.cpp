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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode ret(0);
        ListNode *head = &ret;
        int carry = 0;
        while (l1 || l2)
        {
            int num = 0;
            num += l1 ? l1->val : 0;
            num += l2 ? l2->val : 0;
            num += carry;
            carry = num / 10;
            num = num % 10;
            head->next = new ListNode(num);
            head = head->next;
            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
        }
        if (carry > 0)
        {
            head->next = new ListNode(carry);
        }
        return ret.next;
    }
};