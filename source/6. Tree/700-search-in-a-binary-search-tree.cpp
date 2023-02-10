// Created by Ashechol on 2023/2/10.
// 700. 二叉搜索树中的搜索
// https://leetcode.cn/problems/search-in-a-binary-search-tree/

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

TreeNode* searchBST(TreeNode* cur, int val)
{
    while (cur)
    {
        if (val < cur->val)
            cur = cur->left;
        else if (val > cur->val)
            cur = cur->right;
        else
            return cur;
    }

    return nullptr;
}

int main()
{
    int n, t;
    cin >> n >> t;
    vector<string> nodes(n);

    for (string& node: nodes) cin >> node;

    TreeNode* root = createTree(nodes);

    TreeNode* res = searchBST(root, t);

    queue<TreeNode*> que;
    if (res) que.push(res);

    while (!que.empty())
    {
        TreeNode* cur = que.front();
        que.pop();
        cout << cur->val << " ";

        if (cur->left) que.push(cur->left);
        if (cur->right) que.push(cur->right);
    }

    cout << "\b" << endl;

    return 0;
}
