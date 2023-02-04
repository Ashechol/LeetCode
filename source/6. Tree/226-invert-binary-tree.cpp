// Created by Ashechol on 2023/2/3.
// 226. 翻转二叉树
// https://leetcode.cn/problems/invert-binary-tree/

#include <iostream>
#include <vector>
#include <LeetCode.h>

using namespace std;

TreeNode* dfs(TreeNode* cur)
{
    if (!cur) return nullptr;

    swap(cur->left, cur->right);
    dfs(cur->left);
    dfs(cur->right);

    return cur;
}

int main()
{
    int n;
    cin >> n;

    TreeNode* root = TreeNode::cinTree(n);
    root = dfs(root);

    TreeNode::coutTree(root);

    return 0;
}