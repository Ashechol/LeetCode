// Created by Ashechol on 2022/9/21.
// 203. 移除链表元素
// 题目链接：203. 移除链表元素
// 题解链接：https://www.wolai.com/hMAJ8e8d29PkLcFiNEbUT4#d1utUbsRRtXvb9bfhsv7gT

#include <iostream>
#include "ListNode.h"

using namespace std;

ListNode* removeElements(ListNode* head, int val)
{
    auto* newHead = new ListNode(0, head);

    for (ListNode* p = newHead; p != nullptr; p = p->next)
    {
        while (p->next != nullptr && p->next->val == val)
        {
            ListNode* node = p->next;
            p->next = node->next;
            delete node;
        }
    }

    head = newHead->next;
    delete newHead;
    return head;
}

int main()
{
    int n, val;
    cin >> n >> val;

    ListNode *t = cinListNode(n);

    t = removeElements(t, val);

    printListNode(t);

    return 0;
}