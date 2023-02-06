// Created by Ashechol on 2023/2/5.
// 222. 完全二叉树的节点个数
// https://leetcode.cn/problems/count-complete-tree-nodes/

#include <iostream>
#include <vector>
#include "LeetCode.h"
#include <cmath>

using namespace std;

int countNodes(TreeNode* cur)
{
    if (!cur) return 0;

    return countNodes(cur->left) + countNodes(cur->right) + 1;
}

int count(TreeNode* cur)
{
    if (!cur) return 0;

    int cntL = 1, cntR = 1;
    TreeNode *tmp = cur->left;

    while (tmp)
    {
        tmp = tmp->left;
        cntL++;
    }
    tmp = cur->right;
    while (tmp)
    {
        tmp = tmp->right;
        cntR++;
    }

    if (cntL == cntR) return (1 << cntL) - 1;

    return count(cur->left) + count(cur->right) + 1;
}

int main()
{
    int n;
    cin >> n;
    vector<string> nodes(n);

    for (string& node: nodes) cin >> node;

    TreeNode* root = TreeNode::createTree(nodes);

    cout << count(root) << endl;
    return 0;
}