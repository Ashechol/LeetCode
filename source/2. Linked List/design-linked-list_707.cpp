// Created by Ashechol on 2022/9/21.
// 707. 设计链表
// 题目链接：https://leetcode.cn/problems/design-linked-list/
// 题解链接：https://www.wolai.com/hMAJ8e8d29PkLcFiNEbUT4#mYuSEnb3Vh2XuRviwahEh3

#include <iostream>
#include "LinkedList.h"
#include "LeetCode.h"

using namespace std;


int main()
{
    LinkedList test;

    test.addAtHead(7);
    test.addAtHead(2);
    test.addAtHead(1);
    test.addAtIndex(3, 0);
    test.deleteAtIndex(2);
    test.addAtHead(6);
    test.addAtTail(4);
    cout << test.get(4) << endl;
    test.addAtHead(4);
    test.addAtIndex(5, 0);
    test.addAtHead(6);
}
