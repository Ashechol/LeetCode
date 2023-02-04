// Created by Ashechol on 2023/2/4.
// 100. 相同的树
// https://leetcode.cn/problems/same-tree/

#include <iostream>
#include <queue>
#include "LeetCode.h"

using namespace std;

bool isSame(TreeNode* a, TreeNode* b)
{
    if (!a && !b) return true;
    if (!a || !b) return false;
    if (a->val != b->val) return false;

    return isSame(a->left, b->left) && isSame(a->right, b->right);
}

bool isSameIteration(TreeNode* a, TreeNode* b)
{
    queue<TreeNode*> que;
    que.push(a);
    que.push(b);

    while (!que.empty())
    {
        TreeNode* curA = que.front(); que.pop();
        TreeNode* curB = que.front(); que.pop();

        if (!curA && !curB) continue;
        if (!curA || !curB) return false;
        if (curA->val != curB->val) return false;

        que.push(curA->left);
        que.push(curB->left);
        que.push(curA->right);
        que.push(curB->right);
    }

    return true;
}

int main()
{
    int n;
    cin >> n;

    TreeNode* treeA = TreeNode::cinTree(n);
    TreeNode* treeB = TreeNode::cinTree(n);

    cout << isSame(treeA, treeB) << endl;

    return 0;
}