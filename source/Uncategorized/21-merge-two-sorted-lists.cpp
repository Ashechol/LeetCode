// Created by Ashechol on 2023/2/27.
// 21. 合并两个有序链表
// https://leetcode.cn/problems/merge-two-sorted-lists/

#include <iostream>
#include <vector>

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;

    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* mergeTwoLists(ListNode* cur1, ListNode* cur2)
{
    auto dummy = new ListNode(0);
    ListNode* p = dummy;

    while (cur1 && cur2)
    {
        if (cur1->val < cur2->val)
        {
            p->next = cur1;
            cur1 = cur1->next;
        }
        else
        {
            p->next = cur2;
            cur2 = cur2->next;
        }

        p = p->next;
    }

    if (cur1) p->next = cur1;
    if (cur2) p->next = cur2;

    return dummy->next;
}

int main()
{
    int m, n;
    cin >> m >> n;
    ListNode *head1, *head2, *p;
    head1 = new ListNode(0); head2 = new ListNode(0);
    p = head1;
    while (m--)
    {
        cin >> p->val;
        if (m > 0) p->next = new ListNode(0);
        p = p->next;
    }
    p = head2;
    while (n--)
    {
        cin >> p->val;
        if (n > 0) p->next = new ListNode(0);
        p = p->next;
    }

    ListNode* res = mergeTwoLists(head1, head2);

    while(res)
    {
        cout << res->val << "\n "[res->next != nullptr];
        res = res->next;
    }

    return 0;
}