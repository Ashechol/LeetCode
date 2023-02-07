// Created by Ashechol on 2023/2/7.
// 404. 左叶子之和
// https://leetcode.cn/problems/sum-of-left-leaves/

#include <iostream>
#include <vector>
#include "LeetCode.h"

using namespace std;

void sum(TreeNode* cur, int& res)
{
    if (!cur) return;

    if (cur->left && !cur->left->left && !cur->left->right)
        res += cur->left->val;

    sum(cur->left, res);
    sum(cur->right, res);
}

int sumOfLeftLeaves(TreeNode* root)
{
    int res = 0;
    sum(root, res);
    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<string> nodes(n);
    for (string& node: nodes) cin >> node;

    TreeNode* root = TreeNode::createTree(nodes);

    cout << sumOfLeftLeaves(root) << endl;
    return 0;
}