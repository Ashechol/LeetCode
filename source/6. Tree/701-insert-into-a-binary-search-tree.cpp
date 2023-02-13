// Created by Ashechol on 2023/2/12.
// 701. 二叉搜索树中的插入操作
// https://leetcode.cn/problems/insert-into-a-binary-search-tree/

#include <iostream>
#include <vector>
#include <queue>
#include "LeetCode.h"

using namespace std;

TreeNode* insertIntoBST(TreeNode* cur, int val)
{
    if (!cur) return new TreeNode(val);

    if (val < cur->val)
        cur->left = insertIntoBST(cur->left, val);
    if (val > cur->val)
        cur->right = insertIntoBST(cur->right, val);

    return cur;
}

int main()
{
    int n, val;
    cin >> n >> val;

    vector<string> nodes(n);

    for (string& node: nodes) cin >> node;

    TreeNode* root = TreeNode::createTree(nodes);
    root = insertIntoBST(root, val);

    queue<TreeNode*> que;
    if (root) que.push(root);

    while (!que.empty())
    {
        TreeNode* cur = que.front();
        que.pop();
        cout << cur->val << " ";

        if (cur->left) que.push(cur->left);
        if (cur->right) que.push(cur->right);
    }

    cout << '\b' << endl;

    return 0;
}