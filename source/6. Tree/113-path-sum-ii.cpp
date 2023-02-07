// Created by Ashechol on 2023/2/7.
// 113. 路径总和 II
// https://leetcode.cn/problems/path-sum-ii/

#include <iostream>
#include <vector>
#include "LeetCode.h"

using namespace std;

vector<vector<int>> res;
vector<int> tmpPath;

void path(TreeNode* cur, int target)
{
    if (!cur) return;

    tmpPath.emplace_back(cur->val);

    if (target == cur->val && !cur->left && !cur->right)
        res.emplace_back(tmpPath);

    path(cur->left, target - cur->val);
    path(cur->right, target - cur->val);
    tmpPath.pop_back();
}

vector<vector<int>> pathSum(TreeNode* root, int targetSum)
{
    path(root, targetSum);
    return res;
}

int main()
{
    int n, targetSum;
    cin >> n >> targetSum;
    vector<string> nodes(n);
    for (string& node: nodes) cin >> node;
    TreeNode* root = TreeNode::createTree(nodes);

    vector<vector<int>> ans = pathSum(root, targetSum);

    for (const vector<int>& p: ans)
    {
        for (int val: p)
            cout << val << " ";
        cout << "\b" << endl;
    }

    return 0;
}