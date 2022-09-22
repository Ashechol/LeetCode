// Created by Ashechol on 2022/9/21.

#pragma once

#include <iostream>

using namespace std;

struct ListNode
{
    int val{};
    ListNode* next;
    explicit ListNode(int x = 0) : val(x), next(nullptr) {}
    explicit ListNode(ListNode* next) : next(next) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

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

inline void coutListNode(ListNode* p)
{
    for (; p != nullptr; p = p->next)
    {
        cout << p->val << " ";
    }

    cout << "\b\n";
}