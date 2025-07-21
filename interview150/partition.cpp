/**
 * xiebaoma
 * 2025-07-21
 */

#include<vector>
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
    ListNode *partition(ListNode *head, int x)
    {
        vector<int> lower;
        vector<int> height;
        while(head){
            if(head->val<x){
                lower.push_back(head->val);
            }else{
                height.push_back(head->val);
            }
            head=head->next;
        }
        ListNode dummy(0);
        ListNode* node=& dummy;
        for(int val: lower){
            node->next= new ListNode(val);
            node= node->next;
        }
        for(int val: height){
            node-> next=new ListNode(val);
            node=node->next;
        }
        return dummy.next;
    }
};