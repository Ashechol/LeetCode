// Created by Ashechol on 2023/2/2.
// 94. 二叉树的中序遍历
// https://leetcode.cn/problems/binary-tree-inorder-traversal/

#include <iostream>
#include <vector>
#include <stack>
#include <LeetCode.h>

using namespace std;

void traversal(TreeNode* cur, vector<int>& res)
{
    if (cur == nullptr) return;

    traversal(cur->left, res);
    res.emplace_back(cur->val);
    traversal(cur->right, res);
}

vector<int> inorderTraversal(TreeNode* root)
{
    vector<int> res;
    stack<TreeNode*> stk;

    TreeNode* cur = root;
    while (cur || !stk.empty())
    {
        if (cur)
        {
            stk.push(cur);
            cur = cur->left;
        }
        else
        {
            cur = stk.top();
            stk.pop();
            res.emplace_back(cur->val);
            cur = cur->right;
        }
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

    vector<int> res;
    // traversal(root, res);
    res = inorderTraversal(root);

    for (int num: res) cout << num << " ";
    cout << "\b\n";
}
