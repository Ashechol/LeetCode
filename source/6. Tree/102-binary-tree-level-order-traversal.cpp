// Created by Ashechol on 2023/2/2.
// 102. 二叉树的层序遍历
// https://leetcode.cn/problems/binary-tree-level-order-traversal/
#include <iostream>
#include <queue>
#include <vector>
#include "LeetCode.h"

using namespace std;

vector<vector<int>> levelOrder(TreeNode* root)
{
    vector<vector<int>> res;
    if (!root) return res;

    queue<TreeNode*> que;
    que.push(root);

    while (!que.empty())
    {
        vector<int> nodes;
        int cnt = que.size();
        for (int i = 0; i < cnt; i++)
        {
            TreeNode* node = que.front();
            nodes.emplace_back(node->val);
            if (node->left) que.push(node->left);
            if (node->right) que.push(node->right);
            que.pop();
        }
        res.emplace_back(nodes);
    }

    return res;
}

vector<int> levelOrderTraversal(TreeNode* root)
{
    vector<int> res;
    queue<TreeNode*> que;
    if (root) que.push(root);

    while (!que.empty())
    {
        TreeNode* cur = que.front();
        res.push_back(cur->val);

        if (cur->left) que.push(cur->left);
        if (cur->right) que.push(cur->right);

        que.pop();
    }

    return res;
}

void recursion(TreeNode* cur, vector<vector<int>>& res, int depth)
{
    if (!cur) return;

    if (res.size() == depth) res.emplace_back();
    res[depth].emplace_back(cur->val);

    recursion(cur->left, res, depth + 1);
    recursion(cur->right, res, depth + 1);
}

vector<vector<int>> recursionLeveOrder(TreeNode* root)
{
    vector<vector<int>> res;

    recursion(root, res, 0);

    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<string> nodes(n);

    for (string& node: nodes) cin >> node;
    TreeNode* root = TreeNode::createTree(nodes);

    vector<vector<int>> res = recursionLeveOrder(root);

    for (const vector<int>& level: res)
    {
        for (int node: level)
            cout << node << " ";
        cout << "\b\n";
    }

    vector<int> res2 = levelOrderTraversal(root);

    for (int val: res2) cout << val << " ";
    cout << "\b\n";

    return 0;
}
