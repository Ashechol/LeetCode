// Created by Ashechol on 2023/2/10.
// 530. 二叉搜索树的最小绝对差
// https://leetcode.cn/problems/minimum-absolute-difference-in-bst/

#include <iostream>
#include <vector>
#include "LeetCode.h"

using namespace std;

int res = INT_MAX;
TreeNode* pre = nullptr;
void traversal(TreeNode* cur)
{
    if (!cur) return;

    traversal(cur->left);

    if (pre)
        res = min(res, cur->val - pre->val);

    pre = cur;

    traversal(cur->right);
}

int getMinimumDifference(TreeNode* root)
{
    traversal(root);
    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<string> nodes(n);
    for (string& node: nodes) cin >> node;

    TreeNode* root = TreeNode::createTree(nodes);

    cout << getMinimumDifference(root) << endl;
    return 0;
}