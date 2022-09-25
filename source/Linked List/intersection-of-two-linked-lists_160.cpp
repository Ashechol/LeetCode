// Created by Ashechol on 2022/9/23.
// 160. 相交链表
// 题目链接：https://leetcode.cn/problems/intersection-of-two-linked-lists/
// 题解链接：https://www.wolai.com/hMAJ8e8d29PkLcFiNEbUT4#sKpFo8FnhSFptA8twQa1Tc

#include <iostream>
#include <ListNode.h>
#include <stack>
#include <unordered_map>

using namespace std;

ListNode* getIntersectionNode(ListNode *headA, ListNode *headB);

int main()
{
    int m, n;
    cin >> m >> n;

    ListNode *listA, *listB;

    listA =  cinListNode(m);
    listB =  cinListNode(n);

    ListNode* intersect = getIntersectionNode(listA, listB);

    cout << intersect->val << endl;

    return 0;
}

ListNode* getIntersectionNode(ListNode *headA, ListNode *headB)
{
    int lenA = 0, lenB = 0;
    ListNode *curA = headA, *curB = headB;

    while (curA)
    {
        curA = curA->next;
        lenA++;
    }

    while (curB)
    {
        curB = curB->next;
        lenB++;
    }

    curA = headA;
    curB = headB;

    if (lenA < lenB)
    {
        swap(curA, curB);
        swap(lenA, lenB);
    }

    int gap = lenA - lenB;

    while (gap--) curA = curA->next;

    while (curA && curB)
    {
        if (curA == curB) return curA;

        curA = curA->next;
        curB = curB->next;
    }

    return nullptr;
}

ListNode* getIntersectionNode_simple(ListNode *headA, ListNode *headB)
{
    ListNode *curA = headA, *curB = headB;

    while (curA != curB)
    {
        curA = !curA ? curB : curA->next;
        curB = !curB ? curA : curB->next;
    }

    return curA;
}

ListNode* getIntersectionNode_stack(ListNode *headA, ListNode *headB)
{
    stack<ListNode*> stkA, stkB;
    ListNode* ans = nullptr;

    while (headA)
    {
        stkA.push(headA);
        headA = headA->next;
    }

    while (headB)
    {
        stkB.push(headB);
        headB = headB->next;
    }

    while (!stkA.empty() && !stkB.empty())
    {
        if (stkA.top() != stkB.top())
            break;

        ans = stkA.top();
        stkA.pop();
        stkB.pop();
    }

    return ans;
}

ListNode* getIntersectionNode_hash(ListNode *headA, ListNode *headB)
{
    unordered_map<ListNode*, int> mapA;

    while (headA)
    {
        mapA[headA] = 1;
        headA = headA->next;
    }

    while (headB)
    {
        if (mapA.find(headB) != mapA.end()) return headB;

        headB = headB->next;
    }

    return nullptr;
}