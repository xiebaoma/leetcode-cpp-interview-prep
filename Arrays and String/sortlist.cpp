#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 分割链表为两半
ListNode *getMid(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head->next; // 注意 fast 从 head->next 开始

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode *mid = slow->next;
    slow->next = nullptr; // 断开链表
    return mid;
}

// 合并两个有序链表
ListNode *merge(ListNode *l1, ListNode *l2)
{
    ListNode dummy(0);
    ListNode *tail = &dummy;

    while (l1 && l2)
    {
        if (l1->val < l2->val)
        {
            tail->next = l1;
            l1 = l1->next;
        }
        else
        {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    tail->next = l1 ? l1 : l2;
    return dummy.next;
}

// 主函数：归并排序链表
ListNode *sortList(ListNode *head)
{
    if (!head || !head->next)
        return head;

    ListNode *mid = getMid(head);    // 找中点
    ListNode *left = sortList(head); // 递归排序左边
    ListNode *right = sortList(mid); // 递归排序右边

    return merge(left, right); // 合并两个有序链表
}

// 打印链表
void printList(ListNode *head)
{
    while (head)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// 示例使用
int main()
{
    ListNode *head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);

    cout << "原始链表: ";
    printList(head);

    head = sortList(head);

    cout << "排序后链表: ";
    printList(head);

    return 0;
}
