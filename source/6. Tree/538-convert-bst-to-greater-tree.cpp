// Created by Ashechol on 2023/2/14.
// 538. 把二叉搜索树转换为累加树
// https://leetcode.cn/problems/convert-bst-to-greater-tree/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(const string& node) : val(stoi(node)), left(nullptr), right(nullptr) {}
};

TreeNode* createTree(vector<string> nodes)
{
    if (nodes.empty()) return nullptr;
    if (nodes.size() % 2 == 0) nodes.emplace_back("null");

    auto root = new TreeNode(nodes[0]);
    queue<TreeNode*> que;
    que.push(root);

    for (int i = 1; i < nodes.size(); i += 2)
    {
        TreeNode* cur = que.front();
        que.pop();

        if (nodes[i] != "null")
        {
            cur->left = new TreeNode(nodes[i]);
            que.push(cur->left);
        }

        if (nodes[i+1] != "null")
        {
            cur->right = new TreeNode(nodes[i+1]);
            que.push(cur->right);
        }
    }

    return root;
}

int preSum = 0;
TreeNode* convertBST(TreeNode* cur)
{
    if (!cur) return nullptr;

    convertBST(cur->right);

    cur->val += preSum;
    preSum = cur->val;

    convertBST(cur->left);

    return cur;
}

int main()
{
    int n;
    cin >> n;
    vector<string> nodes(n);
    for (string& node: nodes) cin >> node;

    TreeNode* root = createTree(nodes);

    root = convertBST(root);

    queue<TreeNode*> que;
    if (root) que.push(root);

    while (!que.empty())
    {
        TreeNode* cur = que.front();
        que.pop();

        cout << cur->val << " ";
        if (cur->left) que.push(cur->left);
        if (cur->right) que.push(cur->right);
    }

    return 0;
}
