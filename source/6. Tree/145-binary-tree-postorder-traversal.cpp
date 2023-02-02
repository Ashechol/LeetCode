// Created by Ashechol on 2023/2/2.
// 145. 二叉树的后序遍历
// https://leetcode.cn/problems/binary-tree-postorder-traversal/

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* createTree(vector<string> nodes)
{
    if (nodes.empty()) return nullptr;
    if (nodes.size() % 2 == 0)
        nodes.emplace_back("null");

    TreeNode* root = new TreeNode(stoi(nodes[0]));
    queue<TreeNode*> que;

    que.push(root);

    for (int i = 1; i < nodes.size(); i += 2)
    {
        TreeNode* cur = que.front();

        if (nodes[i] != "null")
        {
            cur->left = new TreeNode(stoi(nodes[i]));
            que.push(cur->left);
        }

        if (nodes[i + 1] != "null")
        {
            cur->right = new TreeNode(stoi(nodes[i + 1]));
            que.push(cur->right);
        }

        que.pop();
    }

    return root;
}

void traversal(TreeNode* cur, vector<int>& res)
{
    if (cur == nullptr) return;

    traversal(cur->left, res);
    traversal(cur->right, res);
    res.emplace_back(cur->val);
}

vector<int> postorderTraversal(TreeNode* root)
{
    if (root == nullptr) return {};

    vector<int> res;
    stack<TreeNode*> stk;
    stk.push(root);

    while (!stk.empty())
    {
        TreeNode* cur = stk.top();
        stk.pop();
        res.emplace_back(cur->val);

        if (cur->left) stk.push(cur->left);
        if (cur->right) stk.push(cur->right);
    }
    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<string> nodes(n);

    for (string& node: nodes) cin >> node;

    TreeNode* root = createTree(nodes);

    vector<int> res = postorderTraversal(root);

    // traversal(root, res);

    for (int num: res) cout << num << " ";
    cout << "\b\n";

    return  0;
}