// Created by Ashechol on 2023/2/7.
// 112. 路径总和
// https://leetcode.cn/problems/path-sum/

#include <iostream>
#include <vector>
#include "LeetCode.h"

using namespace std;

bool hasPathSum(TreeNode* cur, int targetSum)
{
    if (!cur) return false;

    if (targetSum == cur->val && !cur->left && !cur->right)
        return true;

    return hasPathSum(cur->left, targetSum - cur->val) ||
            hasPathSum(cur->right, targetSum - cur->val);
}

int main()
{
    int n, targetSum;
    cin >> n >> targetSum;
    vector<string> nodes(n);
    for (string& node: nodes) cin >> node;

    TreeNode* root = TreeNode::createTree(nodes);
    cout << hasPathSum(root, targetSum) << endl;
    return 0;
}
