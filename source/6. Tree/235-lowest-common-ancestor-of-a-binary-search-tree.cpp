// Created by Ashechol on 2023/2/12.
// 235. 二叉搜索树的最近公共祖先
// https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-search-tree/

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

TreeNode* lowestCommonAncestor(TreeNode* cur, int p, int q)
{
    if (!cur) return cur;

    if (p < cur->val && q < cur->val)
        return lowestCommonAncestor(cur->left, p, q);
    if (p > cur->val && q > cur->val)
        return lowestCommonAncestor(cur->right, p, q);

    return cur;
}

TreeNode* lowestCommonAncestor(TreeNode* cur, TreeNode* p, TreeNode* q)
{
    while (cur)
    {
        if (p->val < cur->val && q->val < cur->val)
            cur = cur->left;
        else if (p->val > cur->val && q->val > cur->val)
            cur = cur->right;
        else
            break;
    }

    return cur;
}

int main()
{
    int n, p, q;
    cin >> n >> p >> q;

    vector<string> nodes(n);
    for (string& node: nodes) cin >> node;

    TreeNode* root = createTree(nodes);
    cout << lowestCommonAncestor(root, p, q)->val << endl;
    return 0;
}
