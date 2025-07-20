/**
 * xiebaoma
 * 2025-07-20
 */

#include <unordered_map>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution
{
public:
    unordered_map<Node *, Node *> cachedNode;

    Node *copyRandomList(Node *head)
    {
        if (head == nullptr)
        {
            return nullptr;
        }
        if (!cachedNode.count(head))
        {
            Node *headNew = new Node(head->val);
            cachedNode[head] = headNew;
            headNew->next = copyRandomList(head->next);
            headNew->random = copyRandomList(head->random);
        }
        return cachedNode[head];
    }
};
