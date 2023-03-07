// Created by Ashechol on 2023/3/4.
// 92. 反转链表 II
// https://leetcode.cn/problems/reverse-linked-list-ii/

#include <iostream>
#include "LeetCode.h"

using namespace std;

ListNode* reverseBetween(ListNode* head, int left, int right)
{
    if (!head->next || left == right) return head;

    ListNode *pre = nullptr, *front = head;
    ListNode* cur = head;

    for (int i = 1; i <= right; i++)
    {
        if (i+1 == left) front = cur;
        if (i == right) pre = cur->next;

        cur = cur->next;
    }
    cur = left > 1 ? front->next : front;
    for (int i = 0; i < right - left + 1; i++)
    {
        ListNode* tmp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = tmp;
    }
    if(left > 1) front->next = pre;

    return head;
}

int main()
{
    int n, left, right;
    cin >> n >> left >> right;
    ListNode* head = ListNode::cinListNode(n);
    head = reverseBetween(head, left, right);
    ListNode::coutListNode(head);
    return 0;
}