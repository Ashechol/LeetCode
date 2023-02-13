// Created by Ashechol on 2023/2/12.
// 450. 删除二叉搜索树中的节点
// https://leetcode.cn/problems/delete-node-in-a-bst/

#include <iostream>
#include <vector>
#include "LeetCode.h"

using namespace std;

TreeNode* deleteNode(TreeNode* cur, int key)
{
    if (!cur) return nullptr;

    if (key < cur->val)
        cur->left = deleteNode(cur->left, key);
    else if (key > cur->val)
        cur->right = deleteNode(cur->right, key);
    else
    {
        TreeNode* node;
        if (!cur->left) node = cur->right;
        else if (!cur->right) node = cur->left;
        else
        {
            TreeNode* tmp = cur->right;
            while (tmp->left) tmp = tmp->left;
            tmp->left = cur->left;
            node = cur->right;
        }
        delete cur;
        return node;
    }

    return cur;
}

int main()
{
    int n, key;
    cin >> n >> key;
    vector<string> nodes(n);
    for (string& node: nodes) cin >> node;
    TreeNode* root = TreeNode::createTree(nodes);

    root = deleteNode(root, key);

    TreeNode::coutTree(root);
    return 0;
}
