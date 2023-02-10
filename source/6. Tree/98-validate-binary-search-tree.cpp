// Created by Ashechol on 2023/2/10.
// 98. 验证二叉搜索树
// https://leetcode.cn/problems/validate-binary-search-tree/

#include <iostream>
#include <vector>
#include "LeetCode.h"

using namespace std;


bool check(TreeNode* cur, int64_t minVal, int64_t maxVal)
{
    if (!cur) return true;

    if (cur->val >= maxVal || cur->val <= minVal)
        return false;

    return check(cur->left, minVal, cur->val) && check(cur->right, cur->val, maxVal);
}

bool isValidBST(TreeNode* root)
{
    return check(root, LLONG_MIN, LLONG_MAX);
}

int main()
{
    int n;
    cin >> n;
    vector<string> nodes(n);

    for (string& node: nodes) cin >> node;
    TreeNode* root = TreeNode::createTree(nodes);

    cout << isValidBST(root) << endl;
    return 0;
}