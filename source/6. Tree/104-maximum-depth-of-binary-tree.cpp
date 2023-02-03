// Created by Ashechol on 2023/2/3.
// 104. 二叉树的最大深度
// https://leetcode.cn/problems/maximum-depth-of-binary-tree/

#include <iostream>
#include <vector>
#include <queue>
#include <LeetCode.h>

using namespace std;

void dfs(TreeNode* cur, int& res, int depth)
{
    if (!cur) return;

    if (depth > res) res = depth;

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

        while (size--)
        {
            TreeNode* cur = que.front();
            que.pop();
            if (cur->left) que.push(cur->left);
            if (cur->right) que.push(cur->right);
        }

        res++;
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

    int res = 0;
    res = bfs(root);
    // dfs(root, res, 1);
    cout << res << endl;

    return 0;
}