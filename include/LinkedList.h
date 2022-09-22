// Created by Ashechol on 2022/9/21.
//

#ifndef LEETCODE_LINKEDLIST_H
#define LEETCODE_LINKEDLIST_H

#include <iostream>

struct ListNode;

class LinkedList
{
private:
    ListNode* _dummyHead;

public:
    int size = 0;

    LinkedList();

    [[nodiscard]] int get(int index) const;

    void addAtHead(int val);

    void addAtTail(int val);

    void addAtIndex(int index, int val);

    void deleteAtIndex(int index);
};

#endif