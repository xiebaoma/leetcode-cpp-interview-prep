#include <unordered_set>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
};


class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> nodes;
        while(headA){
            nodes.emplace(headA);
            headA=headA->next;
        }
        while(headB){
            if(nodes.find(headB)!=nodes.end()){
                return headB;
            }
            headB=headB->next;
        }
        return nullptr;
    }
};