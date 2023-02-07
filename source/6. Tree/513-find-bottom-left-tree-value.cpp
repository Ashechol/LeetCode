// Created by Ashechol on 2023/2/7.
// 513. 找树左下角的值
// https://leetcode.cn/problems/find-bottom-left-tree-value/

#include <iostream>
#include <vector>
#include <queue>
#include "LeetCode.h"

using namespace std;

int findBottomLeftValue(TreeNode* root)
{
    int res = 0;
    queue<TreeNode*> que;
    if (root) que.push(root);

    while (!que.empty())
    {
        int size =  que.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode* cur = que.front();
            que.pop();

            if (i == 0) res = cur->val;

            if (cur->left) que.push(cur->left);
            if (cur->right) que.push(cur->right);
        }
    }

    return res;
}

void dfs(TreeNode* cur, vector<int>& res, int depth)
{
    if (!cur) return;

    if (depth == res.size()) res.emplace_back(cur->val);

    dfs(cur->left, res, depth + 1);
    dfs(cur->right, res, depth + 1);
}

int solution(TreeNode* root)
{
    vector<int> res;
    dfs(root, res, 0);
    return res[res.size() - 1];
}

int main()
{
    int n;
    cin >> n;
    vector<string> nodes(n);
    for (string& node: nodes) cin >> node;

    auto root = TreeNode::createTree(nodes);

    // cout << findBottomLeftValue(root) << endl;
    cout << solution(root) << endl;
    return 0;
}