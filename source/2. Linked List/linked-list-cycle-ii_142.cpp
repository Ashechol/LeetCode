// Created by Ashechol on 2022/9/25.
// 142. 环形链表 II
// 题目链接：https://leetcode.cn/problems/linked-list-cycle-ii/
// 题解链接：https://www.wolai.com/hMAJ8e8d29PkLcFiNEbUT4#i6JpbpLH4wV2GfrrTpPXcN

#include <iostream>
#include <unordered_map>
#include "LeetCode.h"

using namespace std;

ListNode *detectCycle(ListNode *head);

int main()
{
    int n, t;
    cin >> n >> t;

    ListNode* head;
    head = cinListNodeCircle(n, t);

    cout << detectCycle(head)->val << endl;

    return 0;
}

ListNode *detectCycle_hash(ListNode *head)
{
    unordered_map<ListNode*, int> nodeCount;

    while (head)
    {
        nodeCount[head]++;
        if (nodeCount[head] > 1) return head;

        head = head->next;
    }

    return nullptr;
}

ListNode *detectCycle(ListNode *head)
{
    ListNode *fast = head, *slow = head;

    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;

        if (fast == slow)
        {
            ListNode *p1 = head, *p2 = fast;

            while (p1 != p2)
            {
                p1 = p1->next;
                p2 = p2->next;
            }

            return p1;
        }
    }
    return nullptr;
}