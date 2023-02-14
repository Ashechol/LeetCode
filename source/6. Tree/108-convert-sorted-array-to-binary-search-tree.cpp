// Created by Ashechol on 2023/2/14.
// 108. 将有序数组转换为二叉搜索树
// https://leetcode.cn/problems/convert-sorted-array-to-binary-search-tree/

#include <iostream>
#include <vector>
#include "LeetCode.h"

using namespace std;

TreeNode* makeBST(vector<int>& nums, int bg, int ed)
{
    if (bg >= ed) return nullptr;

    int mid = ed + ((bg - ed) >> 1);

    auto cur = new TreeNode(nums[mid]);
    cur->left = makeBST(nums, bg, mid);
    cur->right = makeBST(nums, mid + 1, ed);

    return cur;
}

TreeNode* sortedArrayToBST(vector<int>& nums)
{
    return makeBST(nums, 0, nums.size());
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int& num: nums) cin >> num;

    TreeNode* root = sortedArrayToBST(nums);
    TreeNode::coutTree(root);
    return 0;
}