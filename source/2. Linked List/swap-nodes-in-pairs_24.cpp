// Created by Ashechol on 2022/9/22.
// 24. 两两交换链表中的节点
// 题目链接：https://leetcode.cn/problems/swap-nodes-in-pairs/
// 题解链接：https://www.wolai.com/hMAJ8e8d29PkLcFiNEbUT4#pReQJmhubHutAKt1HaHenx

#include <iostream>
#include "LeetCode.h"

using namespace std;

ListNode* swapPairs(ListNode* head);

int main()
{
    int n;
    cin >> n;

    ListNode* head = cinListNode(n);

    coutListNode(swapPairs(head));

    return 0;
}

ListNode* swapPairs(ListNode* head)
{
    if (!head || !head->next) return head;

    ListNode *prev = head, *cur = head->next;
    ListNode *tmp = nullptr;
    head = cur;

    while (cur)
    {
        if (tmp) tmp->next = cur;

        prev->next = cur->next;
        cur->next = prev;
        tmp = prev;
        prev = prev->next;
        cur = prev ? prev->next : nullptr;
    }

    return head;
}

ListNode* swapPairs_dummy(ListNode* head)
{
    auto dummy = new ListNode(head);
    ListNode *prev = dummy, *cur = head;

    while (cur && cur->next)
    {
        prev->next = cur->next;
        cur->next = cur->next->next;
        prev->next->next = cur;

        prev = cur;
        cur = cur->next;
    }

    return dummy->next;
}