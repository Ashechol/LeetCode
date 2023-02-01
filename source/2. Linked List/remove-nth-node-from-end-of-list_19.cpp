// Created by Ashechol on 2022/9/23.
// 19. 删除链表的倒数第 N 个结点
// 题目链接：https://leetcode.cn/problems/remove-nth-node-from-end-of-list/
// 题解链接：https://www.wolai.com/hMAJ8e8d29PkLcFiNEbUT4#kXEgdb4c7VcAsLhtoS86zQ

#include <iostream>
#include "LeetCode.h"

using namespace std;

ListNode* removeNthFromEnd(ListNode* head, int n);

int main()
{
    int sz, n;
    cin >>  sz >> n;

    ListNode* head;
    head = cinListNode(sz);

    head = removeNthFromEnd(head, n);

    coutListNode(head);

    return 0;
}

ListNode* removeNthFromEnd(ListNode* head, int n)
{
    auto dummy = new ListNode(0, head);
    ListNode *prev = dummy, *cur = dummy;

    while (n--) cur = cur->next;

    while (cur->next)
    {
        prev = prev->next;
        cur = cur->next;
    }

    ListNode* tmp = prev->next;
    prev->next = tmp->next;
    delete tmp;
    return dummy->next;
}
