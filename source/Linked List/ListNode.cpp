// Created by Ashechol on 2022/9/25.

#include "ListNode.h"
#include <iostream>

using namespace std;

ListNode* cinListNode(int n)
{
    auto* head = new ListNode();
    ListNode* p = head;

    cin >> head->val;

    for (int i = 1; i < n; i++)
    {
        int num;
        cin >> num;
        p->next = new ListNode(num);
        p = p->next;
    }

    return head;
}

ListNode* cinListNodeCircle(int n, int pos)
{
    auto* head = new ListNode();
    ListNode* p = head;
    ListNode* tmp = nullptr;

    cin >> head->val;

    for (int i = 1; i < n; i++)
    {
        int num;
        cin >> num;
        p->next = new ListNode(num);

        if (i - 1 == pos)
            tmp = p;

        p = p->next;
    }
    p->next = tmp;
    return head;
}