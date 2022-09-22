//
// Created by Ashechol on 2022/9/21.
//

#include "LinkedList.h"
#include "ListNode.h"

LinkedList::LinkedList()
{
    _dummyHead = new ListNode(0);
}

int LinkedList::get(int index) const
{
    if (index > size - 1 || index < 0) return -1;

    ListNode* p = _dummyHead->next;

    while (index--) p = p->next;

    return p->val;
}

void LinkedList::addAtHead(int val)
{
    auto node = new ListNode(val);

    node->next = _dummyHead->next;
    _dummyHead->next = node;

    size++;
}

void LinkedList::addAtTail(int val)
{
    auto node = new ListNode(val);
    ListNode* p = _dummyHead;

    while (p->next != nullptr) p = p->next;
    p->next = node;
    size++;
}

void LinkedList::addAtIndex(int index, int val)
{
    if (index > size || index < 0) return;

    ListNode* p = _dummyHead;
    auto node = new ListNode(val);

    while (index--)
        p = p->next;

    node->next = p->next;
    p->next = node;
    size++;
}

void LinkedList::deleteAtIndex(int index)
{
    if (size == 0 || index >= size || index < 0) return;

    ListNode* p = _dummyHead;

    while (index--)
        p = p->next;

    ListNode* tmp = p->next;
    p->next = tmp->next;
    delete tmp;
    size--;
}
