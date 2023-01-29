// Created by Ashechol on 2022/9/22.
// 206. 反转链表
// 题目链接：https://leetcode.cn/problems/reverse-linked-list/
// 题解链接：https://www.wolai.com/hMAJ8e8d29PkLcFiNEbUT4#ptRuYmEjwH8YXz6KTfDeNa

#include <iostream>
#include "ListNode.h"

using namespace std;

ListNode* reverseList(ListNode* head);

int main()
{
    int n;
    cin >> n;
    ListNode* head = cinListNode(n);

    head = reverseList(head);

    coutListNode(head);
    return 0;
}

ListNode* reverseList(ListNode* head)
{
    ListNode *prev = nullptr, *cur = head;

    while (cur)
    {
        ListNode* tmp = cur->next;  // 暂存当前节点
        cur->next = prev;           // 反向
        prev = cur;                 // 更新prev节点到当前节点
        cur= tmp;                   // 更新cur到下一个节点
    }

    return prev;
}

ListNode* reverseList_lite(ListNode* head)
{
    ListNode *prev = nullptr, *cur = head;

    for (; cur; swap(prev, cur))
        swap(prev, cur->next);

    return prev;
}
