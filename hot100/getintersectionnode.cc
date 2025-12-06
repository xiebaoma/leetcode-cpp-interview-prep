/**
 *xiebaoma
 *2025-12-03
 */

#include <cstddef>
#include <unordered_set>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> nodes;
        ListNode* tmp = headA;
        while (tmp)
        {
            nodes.emplace(tmp);
            tmp=tmp->next;
        }
        tmp=headB;
        while (tmp)
        {
            if (nodes.find(tmp)!=nodes.end())
            {
                return tmp;
            }
            tmp=tmp->next;
        }
        return nullptr;
    }
};
