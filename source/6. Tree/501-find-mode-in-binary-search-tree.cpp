// Created by Ashechol on 2023/2/10.
// 501. 二叉搜索树中的众数
// https://leetcode.cn/problems/find-mode-in-binary-search-tree/

#include <iostream>
#include <vector>
#include "LeetCode.h"

using namespace std;

int preVal, cnt, maxCnt;

void traversal(TreeNode* cur, vector<int>& res)
{
    if (!cur) return;

    traversal(cur->left, res);

    if (preVal == cur->val)
        cnt++;
    else
    {
        cnt = 1;
        preVal = cur->val;
    }

    if (cnt == maxCnt)
        res.emplace_back(cur->val);
    if (cnt > maxCnt)
    {
        res = vector<int> {cur->val};
        maxCnt = cnt;
    }

    traversal(cur->right, res);
}

vector<int> findMode(TreeNode* root)
{
    vector<int> res;
    traversal(root, res);
    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<string> nodes(n);

    for (string& node: nodes) cin >> node;

    TreeNode* root = TreeNode::createTree(nodes);

    vector<int> res = findMode(root);

    for (int val: res) cout << val << " ";
    cout << '\b' << endl;
    return 0;
}
