// Created by Ashechol on 2023/2/11.
// 236. 二叉树的最近公共祖先
// https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/

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

bool findTarget(TreeNode* cur, TreeNode* t)
{
    if (!cur)
        return false;
    if (cur == t)
        return true;

    return findTarget(cur->left, t) || findTarget(cur->right, t);
}

TreeNode* lowestCommonAncestor(TreeNode* cur, TreeNode* p, TreeNode* q)
{
    if (!cur) return nullptr;

    bool pL = findTarget(cur->left, p) || cur == p;
    bool pR = findTarget(cur->right, p) || cur == p;
    bool qL = findTarget(cur->left, q) || cur == q;
    bool qR = findTarget(cur->right, q) || cur == q;

    if ((pL && qR) || (pR && qL)) return cur;

    if (pL)
        return lowestCommonAncestor(cur->left, p, q);

    return lowestCommonAncestor(cur->right, p, q);
}

int main()
{

}
