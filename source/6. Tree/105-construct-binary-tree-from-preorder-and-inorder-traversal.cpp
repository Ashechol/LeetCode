// Created by Ashechol on 2023/2/8.
// 105. 从前序与中序遍历序列构造二叉树
// https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

#include <iostream>
#include <vector>
#include <unordered_map>
#include "LeetCode.h"

using namespace std;

unordered_map<int, int> inHash;
vector<int> pre;

TreeNode* build(int preL, int preR, int inL, int inR)
{
    if (preL == preR) return nullptr;

    auto cur = new TreeNode(pre[preL]);

    int mid = inHash[cur->val];

    cur->left = build(preL+1, preL+1+mid-inL, inL, mid);
    cur->right = build(preL+1+mid-inL, preR, mid+1, inR);

    return cur;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
{
    for (int i = 0; i < inorder.size(); i++)
        inHash[inorder[i]] = i;

    pre = preorder;
    int size = preorder.size();
    // [)
    return build(0, size, 0, size);
}

int main()
{
    int n;
    cin >> n;
    vector<int> preorder(n), inorder(n);

    for (int& val: preorder) cin >> val;
    for (int& val: inorder) cin >> val;

    TreeNode* root = buildTree(preorder, inorder);
    TreeNode::coutTree(root);

    return 0;
}

