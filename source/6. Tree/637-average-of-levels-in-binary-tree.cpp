// Created by Ashechol on 2023/2/2.
// 637. 二叉树的层平均值
// https://leetcode.cn/problems/average-of-levels-in-binary-tree/

#include <iostream>
#include <vector>
#include <queue>
#include <LeetCode.h>

using namespace std;

vector<double> solution(TreeNode* root)
{
    vector<double> res;
    queue<TreeNode*> que;

    if (root) que.push(root);

    while (!que.empty())
    {
        double sum = 0.f;
        int size = que.size();

        for (int i = 0; i < size; i++)
        {
            TreeNode* cur = que.front();
            que.pop();

            sum += cur->val;
            if (cur->left) que.push(cur->left);
            if (cur->right) que.push(cur->right);
        }

        res.emplace_back(sum / size);
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
    vector<double> res = solution(root);

    for (double val: res) cout << val << " ";
    cout << "\b\n";
    return 0;
}
