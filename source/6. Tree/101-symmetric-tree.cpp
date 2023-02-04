// Created by Ashechol on 2023/2/4.
// 101. 对称二叉树
// https://leetcode.cn/problems/symmetric-tree/

#include <iostream>
#include <queue>
#include "LeetCode.h"
using namespace std;

bool compare(TreeNode* left, TreeNode* right)
{
    if (!left && !right) return true;
    if (!left || !right) return false;

    bool outside = compare(left->left, right->right);
    bool inside = compare(left->right, right->left);

    return left->val == right->val && outside && inside;
}

bool compareIteration(TreeNode* root)
{
    queue<TreeNode*> que;

    que.push(root->left);
    que.push(root->right);

    while (!que.empty())
    {
        TreeNode* left = que.front();
        que.pop();
        TreeNode* right = que.front();
        que.pop();

        if (!left && !right) continue;
        if (!left || !right) return false;
        if (left->val != right->val) return false;

        que.push(left->left);
        que.push(right->right);
        que.push(left->right);
        que.push(right->left);
    }

    return true;
}

bool solution(TreeNode* root)
{
    return compare(root->left, root->right);
}

int main()
{
    int n;
    cin >> n;
    TreeNode* root = TreeNode::cinTree(n);

    cout << compareIteration(root) << endl;
    return 0;
}
