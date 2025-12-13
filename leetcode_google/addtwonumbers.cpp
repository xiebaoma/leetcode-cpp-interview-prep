/**
 * 2025-06-19
 * xiebaoma
 */

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *head = nullptr;
    ListNode *temp = nullptr;

    int carry = 0;
    while (l1 || l2)
    {
        int val1 = l1 ? l1->val : 0;
        int val2 = l2 ? l2->val : 0;
        int ret = val1 + val2 + carry;
        carry = ret / 10;
        ret %= 10;
        ListNode *node = new ListNode(ret);
        if (temp)
        {
            temp->next = node;
            temp = temp->next;
        }
        else
        {
            temp = node;
            head = temp;
        }

        if (l1)
            l1 = l1->next;
        if (l2)
            l2 = l2->next;
    }

    if (carry > 0)
    {
        ListNode *node = new ListNode(carry);
        if (temp)
        {
            temp->next = node;
        }
        else
        {
            temp = node;
        }
    }
    return head;
}

int main()
{
}