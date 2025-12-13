/**
 * xiebaoma
 * 2025-06-26
 */

#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

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
    vector<int> nextLargerNodes(ListNode *head)
    {
        stack<ListNode *> sta;
        unordered_map<ListNode *, int> map;
        vector<int> ret;
        ListNode *node = head;
        while (node)
        {
            if (sta.empty())
            {
                sta.emplace(node);
                map[node] = 0;
            }
            else
            {
                while (!sta.empty())
                {
                    if (node->val > sta.top()->val)
                    {
                        ListNode *temp = sta.top();
                        map[temp] = node->val;
                        sta.pop();
                    }else{
                        break;
                    }
                }
                sta.emplace(node);
                map[node] = 0;
            }
            node = node->next;
        }
        node = head;
        while (node)
        {
            ret.push_back(map[node]);
            node = node->next;
        }
        return ret;
    }
};