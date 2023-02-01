// Created by Ashechol on 2023/1/31.
// 144. 二叉树的前序遍历

#include <iostream>
#include <vector>
#include <stack>
#include "LeetCode.h"

using namespace std;

vector<int> preorderTraversal(TreeNode* root)
{
    vector<int> res;
    stack<TreeNode*> stk;

    stk.push(root);

    while (!stk.empty())
    {
        TreeNode* tmp = stk.top();
        stk.pop();
        res.push_back(tmp->val);
        if (tmp->right) stk.push(tmp->right);
        if (tmp->left) stk.push(tmp->left);
    }

    return res;
}

int main()
{
    int n;
    cin >> n;
    // vector<string> nodes = {"1", "2", "3", "null", "4", "5", "6"};
    vector<string> nodes(n);

    for (string& node: nodes) cin >> node;

    TreeNode* root = TreeNode::createTree(nodes);

    vector<int> res = preorderTraversal(root);

    for (int num: res) cout << num << " ";
    cout << "\b\n";

    return 0;
}
