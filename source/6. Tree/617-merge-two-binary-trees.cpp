// Created by Ashechol on 2023/2/9.
// 617. 合并二叉树
// https://leetcode.cn/problems/merge-two-binary-trees/

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
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
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

TreeNode* mergeTrees(TreeNode* curA, TreeNode* curB)
{
    if (!curA && !curB) return nullptr;

    if (!curA) return curB;
    if (!curB) return curA;

    curA->val += curB->val;

    curA->left = mergeTrees(curA->left, curB->left);
    curA->right = mergeTrees(curA->right, curB->right);

    return curA;
}

int main()
{
    int m, n;
    cin >> m >> n;

    vector<string> nodesA(m), nodesB(n);

    for (string& node: nodesA) cin >> node;
    for (string& node: nodesB) cin >> node;

    TreeNode* rootA = createTree(nodesA);
    TreeNode* rootB = createTree(nodesB);

    TreeNode* res = mergeTrees(rootA, rootB);

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