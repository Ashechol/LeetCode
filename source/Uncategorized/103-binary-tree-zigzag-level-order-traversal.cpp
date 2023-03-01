// Created by Ashechol on 2023/2/28.
// 103. 二叉树的锯齿形层序遍历
// https://leetcode.cn/problems/binary-tree-zigzag-level-order-traversal/

#include <iostream>
#include <vector>
#include <queue>
#include <deque>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(const string& val) : val(stoi(val)), left(nullptr), right(nullptr) {}
};

vector<vector<int>> zigzagLevelOrder(TreeNode* root)
{
    queue<TreeNode*> que;
    vector<vector<int>> res;
    if (root) que.push(root);

    int level = 0;
    while (!que.empty())
    {
        deque<int> layer;

        int size = que.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode* cur = que.front(); que.pop();

            if (level % 2 == 0)
                layer.emplace_back(cur->val);
            else
                layer.emplace_front(cur->val);

            if (cur->left) que.push(cur->left);
            if (cur->right) que.push(cur->right);
        }
        res.emplace_back(layer.begin(), layer.end());
        level++;
    }

    return res;
}

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

int main()
{
    int n;
    cin >> n;
    vector<string> nodes(n);
    for (string& node: nodes) cin >> node;

    TreeNode* root = createTree(nodes);
    vector<vector<int>> res = zigzagLevelOrder(root);
    for (vector<int>& ans: res)
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << "\n "[i != ans.size()-1];

    return 0;
}
