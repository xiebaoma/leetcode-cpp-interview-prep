#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        ListNode dummy(0, head);
        ListNode *prev = &dummy;

        while (true) {
            // check if there are at least k nodes left
            ListNode *kth = prev;
            for (int i = 0; i < k && kth; i++) {
                kth = kth->next;
            }
            if (!kth) break;

            ListNode *start = prev->next;
            ListNode *curr = start;
            ListNode *nextGroup = kth->next;
            ListNode *pre = nextGroup;

            // reverse the k nodes
            while (curr != nextGroup) {
                ListNode *nxt = curr->next;
                curr->next = pre;
                pre = curr;
                curr = nxt;
            }

            prev->next = pre;
            prev = start;
        }

        return dummy.next;
    }
};

ListNode* buildList(const vector<int>& nums) {
    ListNode dummy;
    ListNode *cur = &dummy;
    for (int x : nums) {
        cur->next = new ListNode(x);
        cur = cur->next;
    }
    return dummy.next;
}

void printList(ListNode *head) {
    while (head) {
        cout << head->val;
        head = head->next;
        if (head) cout << " -> ";
    }
    cout << endl;
}

int main() {
    Solution sol;

    // test case 1
    ListNode *l1 = buildList({1, 2, 3, 4, 5});
    cout << "Input:  1 -> 2 -> 3 -> 4 -> 5, k=2" << endl;
    ListNode *r1 = sol.reverseKGroup(l1, 2);
    cout << "Output: ";
    printList(r1);
    // expected: 2 -> 1 -> 4 -> 3 -> 5

    // test case 2
    ListNode *l2 = buildList({1, 2, 3, 4, 5});
    cout << "\nInput:  1 -> 2 -> 3 -> 4 -> 5, k=3" << endl;
    ListNode *r2 = sol.reverseKGroup(l2, 3);
    cout << "Output: ";
    printList(r2);
    // expected: 3 -> 2 -> 1 -> 4 -> 5

    return 0;
}
