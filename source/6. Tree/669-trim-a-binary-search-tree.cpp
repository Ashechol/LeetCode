// Created by Ashechol on 2023/2/13.
// 669. 修剪二叉搜索树
// https://leetcode.cn/problems/trim-a-binary-search-tree/

#include <iostream>
#include <vector>
#include "LeetCode.h"

using namespace std;

TreeNode* trimBST(TreeNode* cur, int low, int high)
{
    if (!cur) return nullptr;

    if (cur->val < low)
        return trimBST(cur->right, low, high);
    if (cur->val > high)
        return trimBST(cur->left, low, high);

    cur->left = trimBST(cur->left, low, high);
    cur->right = trimBST(cur->right, low, high);

    return cur;
}

int main()
{
    int n, low, high;
    cin >> n >> low >> high;

    vector<string> nodes(n);
    for (string& node: nodes) cin >> node;

    TreeNode* root = TreeNode::createTree(nodes);
    root = trimBST(root, low, high);

    TreeNode::coutTree(root);
    return 0;
}
