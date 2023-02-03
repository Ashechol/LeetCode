// Created by Ashechol on 2022/12/9.
//

#include <iostream>
#include <stack>
#include "LeetCode.h"

using namespace std;

vector<int> traversal(TreeNode* root)
{
    vector<int> res;
    stack<TreeNode*> stk;

    if (root) stk.push(root);

    while (!stk.empty())
    {
        TreeNode* cur = stk.top();

        if (cur)
        {
            stk.pop();

            if (cur->right) stk.push(cur->right);
            if (cur->left) stk.push(cur->left);
            stk.push(cur);
            stk.push(nullptr);
        }
        else
        {
            stk.pop();
            res.emplace_back(stk.top()->val);
            stk.pop();
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
    vector<int> res = traversal(root);

    for (int val: res) cout << val << " ";
    cout << "\b\n";

    return 0;
}