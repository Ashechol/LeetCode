// Created by Ashechol on 2023/2/6.
// 257. 二叉树的所有路径
// https://leetcode.cn/problems/binary-tree-paths/

#include <iostream>
#include <vector>
#include "LeetCode.h"

using namespace std;

void path(TreeNode* cur, vector<string>& res, string p)
{
    if (!cur) return;

    p += to_string(cur->val);

    if (!cur->left && !cur->right)
    {
        res.emplace_back(p);
        return;
    }

    path(cur->left, res, p + "->");
    path(cur->right, res, p + "->");
}

vector<string> binaryTreePaths(TreeNode* root)
{
    vector<string> res;
    path(root, res, "");
    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<string> nodes(n);

    for (string& node: nodes) cin >> node;

    TreeNode* root = TreeNode::createTree(nodes);

    vector<string> res = binaryTreePaths(root);

    for (const string& val: res) cout << val << " ";
    cout << "\b" << endl;

    return 0;
}
