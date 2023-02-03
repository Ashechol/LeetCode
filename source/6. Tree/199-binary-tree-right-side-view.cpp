// Created by Ashechol on 2023/2/2.
// 199. 二叉树的右视图
// https://leetcode.cn/problems/binary-tree-right-side-view/

#include <iostream>
#include <vector>
#include <queue>
#include <LeetCode.h>

using namespace std;

vector<int> rightSideView(TreeNode* root)
{
    vector<int> res;
    queue<TreeNode*> que;
    if (root) que.push(root);

    while (!que.empty())
    {
        TreeNode* cur;
        int size = que.size();
        int last = 0;

        while (size--)
        {
            cur = que.front();
            last = cur->val;
            if (cur->left) que.push(cur->left);
            if (cur->right) que.push(cur->right);
            que.pop();
        }

        res.push_back(last);
    }

    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<string> nodes(n);

    for (string& node: nodes) cin >> node;
    TreeNode* root = TreeNode::createTree(nodes);

    vector<int> res = rightSideView(root);

    for (int val: res) cout << val << " ";
    cout << "\b\n";

    return 0;
}