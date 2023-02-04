// Created by Ashechol on 2023/2/1.
//

#ifndef LEETCODE_LEETCODE_H
#define LEETCODE_LEETCODE_H

#include <iostream>
#include <vector>
#include <string>

class ListNode
{
public:
    int val{};
    ListNode* next;

    explicit ListNode(int x = 0) : val(x), next(nullptr) {}
    explicit ListNode(ListNode* next) : next(next) {}

    /// cin a normal list
    /// \param n node num
    static ListNode* cinListNode(int n);

    /// cin a circle list
    /// \param n node num
    /// \param pos start end pos
    static ListNode* cinListNodeCircle(int n, int pos);

    /// cout list
    static inline void coutListNode(ListNode* p)
    {
        for (; p != nullptr; p = p->next)
            std::cout << p->val << " ";

        std::cout << "\b\n";
    }
};

class TreeNode
{
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    explicit TreeNode(int x = 0) : val(x), left(nullptr), right(nullptr) {}

    /// Create a binary tree whose nodes in level order
    /// \param nodes "null" means null node
    static TreeNode* createTree(std::vector<std::string> nodes);

    /// Create a binary tree by using a Complete Binary Tree array
    /// \param nodes "null" means null node
    static TreeNode* createTreeCBT(const std::vector<std::string>& nodes);

    /// cin in level order, "null" means null node
    static TreeNode* cinTree(int n);

    /// cout in level order
    static void coutTree(TreeNode* root);
};

#endif //LEETCODE_LEETCODE_H
