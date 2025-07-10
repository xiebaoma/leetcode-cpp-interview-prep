/**
 * xiebaoma
 * 2025-07-10
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
    ListNode *reverseList(ListNode *head)
    {
        if(head==nullptr){
            return nullptr;
        }
        ListNode *pre = nullptr;
        ListNode *node = head;
        ListNode *next = head->next;
        while (node)
        {
            node->next = pre;
            pre = node;
            node = next;
            if (next == nullptr)
            {
            }
            else
            {
                next = next->next;
            }
        }
        head= pre;
        return head;
    }
};