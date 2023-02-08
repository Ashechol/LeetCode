// Created by Ashechol on 2023/2/7.
// 106. 从中序与后序遍历序列构造二叉树
// https://leetcode.cn/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

#include <iostream>
#include <vector>
#include <unordered_map>
#include "LeetCode.h"

using namespace std;

unordered_map<int, int> inorderHash;
vector<int> post;

TreeNode* dfs(int inL, int inR, int postL, int postR)
{
    if (postL == postR) return nullptr;

    auto cur = new TreeNode(post[postR-1]);

    int mid = inorderHash[cur->val];

    cur->left = dfs(inL, mid, postL, postL+mid-inL);
    cur->right = dfs(mid+1, inR, postL+mid-inL, postR-1);

    return cur;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
{
    for (int i = 0; i < inorder.size(); i++)
        inorderHash[inorder[i]] = i;
    post = postorder;
    int size = inorder.size();
    return dfs(0, size, 0, size);
}

int main()
{
    int n;
    cin >> n;
    vector<int> inorder(n), postorder(n);

    for (int& val: inorder) cin >> val;
    for (int& val: postorder) cin >> val;

    TreeNode* root = buildTree(inorder, postorder);

    TreeNode::coutTree(root);

    return 0;
}
