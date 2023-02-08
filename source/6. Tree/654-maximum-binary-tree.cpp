// Created by Ashechol on 2023/2/8.
// 654. 最大二叉树
// https://leetcode.cn/problems/maximum-binary-tree/

#include <iostream>
#include <vector>
#include <deque>
#include "LeetCode.h"

using namespace std;

TreeNode* build(const vector<int>& nums, int left, int right)
{
    if (left == right) return nullptr;

    int maxValInd = left;
    for (int i = left; i < right; i++)
        if (nums[i] > nums[maxValInd])
            maxValInd = i;

    auto cur = new TreeNode(nums[maxValInd]);

    cur->left = build(nums, left, maxValInd);
    cur->right = build(nums, maxValInd + 1, right);

    return cur;
}

TreeNode* maximumBinaryTree(vector<int>& nums)
{
    deque<TreeNode*> dq;
    for (int num : nums)
    {
        auto node = new TreeNode(num);

        while (!dq.empty())
        {
            if (node->val < dq.back()->val)
            {
                dq.back()->right = node;
                dq.push_back(node);
                break;
            }

            node->left = dq.back();
            dq.pop_back();
        }

        if (dq.empty()) dq.push_back(node);
    }

    return dq.front();
}

TreeNode* constructMaximumBinaryTree(vector<int>& nums)
{
    return build(nums, 0, nums.size());
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);

    for (int& val: nums) cin >> val;

    TreeNode* root = maximumBinaryTree(nums);
    TreeNode::coutTree(root);

    return 0;
}
