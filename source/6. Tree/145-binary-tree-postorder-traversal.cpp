// Created by Ashechol on 2023/2/2.
// 145. 二叉树的后序遍历
// https://leetcode.cn/problems/binary-tree-postorder-traversal/

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include "LeetCode.h"

using namespace std;

void traversal(TreeNode* cur, vector<int>& res)
{
    if (cur == nullptr) return;

    traversal(cur->left, res);
    traversal(cur->right, res);
    res.emplace_back(cur->val);
}

vector<int> postorderTraversal(TreeNode* root)
{
    if (root == nullptr) return {};

    vector<int> res;
    stack<TreeNode*> stk;
    stk.push(root);

    while (!stk.empty())
    {
        TreeNode* cur = stk.top();
        stk.pop();
        res.emplace_back(cur->val);

        if (cur->left) stk.push(cur->left);
        if (cur->right) stk.push(cur->right);
    }
    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<string> nodes(n);

    for (string& node: nodes) cin >> node;

    TreeNode* root = TreeNode::createTree(nodes);

    vector<int> res = postorderTraversal(root);

    // traversal(root, res);

    for (int num: res) cout << num << " ";
    cout << "\b\n";

    return  0;
}