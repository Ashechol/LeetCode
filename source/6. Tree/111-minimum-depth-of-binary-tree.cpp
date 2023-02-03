// Created by Ashechol on 2023/2/3.
// 111. 二叉树的最小深度
// https://leetcode.cn/problems/minimum-depth-of-binary-tree/

#include <iostream>
#include <queue>
#include "LeetCode.h"

using namespace std;

void dfs(TreeNode* cur, int& res, int depth)
{
    if (!cur)
    {
        res = min(depth, res);
        return;
    }

    if (!cur->left && !cur->right)
        res = min(depth, res);

    dfs(cur->left, res, depth + 1);
    dfs(cur->right, res, depth + 1);
}

int bfs(TreeNode* root)
{
    int res = 0;
    queue<TreeNode*> que;
    if (root) que.push(root);

    while (!que.empty())
    {
        int size = que.size();
        res++;
        while (size--)
        {
            TreeNode* cur = que.front();
            que.pop();
            if (!cur->left && !cur->right)
                return res;

            if (cur->left) que.push(cur->left);
            if (cur->right) que.push(cur->right);
        }
    }

    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<string> nodes(n);

    for (string& node: nodes) cin >> node;

    TreeNode* root = TreeNode::createTree(nodes);

    int res = INT_MAX;
    // dfs(root, res, 1);
    res = bfs(root);

    cout << res << endl;

    return 0;
}