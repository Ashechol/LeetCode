// Created by Ashechol on 2023/2/3.
// 25. K 个一组翻转链表
// https://leetcode.cn/problems/reverse-nodes-in-k-group/

#include <iostream>
#include "LeetCode.h"

using namespace std;

ListNode* reverse(ListNode* head, ListNode* tail)
{
    ListNode* pre = head;
    ListNode* cur = head->next;

    pre->next = tail;
    while (cur != tail)
    {
        ListNode* tmp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = tmp;
    }
    return head;
}

ListNode* reverseKGroup(ListNode* head, int k)
{
    auto dummy = new ListNode();
    dummy->next = head;
    ListNode* pre = dummy, *groupTail = head;
    int cnt = 0;

    while (groupTail->next)
    {
        while (++cnt < k && groupTail->next)
            groupTail = groupTail->next;
        if (cnt < k) break;
        cnt = 0;
        ListNode* tmp = pre->next;
        pre->next = groupTail; groupTail = groupTail->next;
        pre = reverse(tmp, groupTail);
    }

    return dummy->next;
}

int main()
{
    int n;
    cin >> n;
    ListNode* head = ListNode::cinListNode(n);

    int k; cin >> k;
    head = reverseKGroup(head, k);
    ListNode::coutListNode(head);
    return 0;
}