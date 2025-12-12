/*
// Definition for a Node.

*/

#include <unordered_map>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> oldmap;
        unordered_map<Node*, Node*> newmap;
        Node dummy(0);
        Node* pre = &dummy;
        Node* old = head;
        while (old)
        {
            pre->next =new Node(old->val);
            pre=pre->next;
            oldmap[old] =pre;
            newmap[pre] =old;
            old =old->next;
        }
        pre = dummy.next;
        while (pre)
        {
            Node* old = newmap[pre];
            Node* oldrandom =old->random;
            if (!oldrandom)
            {
                pre->random=nullptr;
            }else
            {
                pre->random=oldmap[oldrandom];
            }
            pre=pre->next;
        }
        return dummy.next;
    }
};