// Created by Ashechol on 2023/2/2.
// 515. 在每个树行中找最大值
// https://leetcode.cn/problems/find-largest-value-in-each-tree-row/

#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<int> bfs(TreeNode* root)
{
    vector<int> res;
    queue<TreeNode*> que;

    if (root) que.push(root);

    while (!que.empty())
    {
        int size = que.size();
        int m = INT_MIN;
        while (size--)
        {
            TreeNode* cur = que.front();
            que.pop();
            if (cur->val > m) m = cur->val;

            if (cur->left) que.push(cur->left);
            if (cur->right) que.push(cur->right);
        }

        res.push_back(m);
    }

    return res;
}

void dfs(vector<int>& res, TreeNode* cur, int depth)
{
    if (!cur) return;

    if (res.size() == depth)
        res.emplace_back(cur->val);
    else
        res[depth] = max(cur->val, res[depth]);

    dfs(res, cur->left, depth + 1);
    dfs(res, cur->right, depth + 1);
}


int main()
{
    TreeNode* root = new TreeNode(0);
    TreeNode* c1 = new TreeNode(-1);
    // TreeNode* c2 = new TreeNode(2);
    // auto c3 = new TreeNode(5);
    // auto c4 = new TreeNode(3);
    // auto c5 = new TreeNode(9);
    // root->left = c1; root->right = c2;
    // c1->left = c3; c1->right = c4;
    // c2->right = c5;
    root->left = c1;
    vector<int> res = bfs(root);

    for (int val: res) cout << val << " ";
    cout << "\b\n";

    return 0;
}