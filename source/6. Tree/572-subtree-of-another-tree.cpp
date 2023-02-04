// Created by Ashechol on 2023/2/4.
// 572. 另一棵树的子树
// https://leetcode.cn/problems/subtree-of-another-tree/

#include <iostream>
#include "LeetCode.h"

using namespace std;

bool isSameTree(TreeNode* cur, TreeNode* subCur)
{
    if (!cur && !subCur) return true;
    if (!cur || !subCur) return false;
    if (cur->val != subCur->val) return false;

    return isSameTree(cur->left, subCur->left) && isSameTree(cur->right, subCur->right);
}

bool isSubtree(TreeNode* cur, TreeNode* subRoot)
{
    if (!cur) return false;
    if (isSameTree(cur, subRoot)) return true;

    return isSubtree(cur->left, subRoot) || isSubtree(cur->right, subRoot);
}

int main()
{
    int n, m;
    cin >> n >> m;
    TreeNode* root = TreeNode::cinTree(n);
    TreeNode* subRoot = TreeNode::cinTree(m);

    cout << isSubtree(root, subRoot) << endl;
    return 0;
}
