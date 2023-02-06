// Created by Ashechol on 2023/2/6.
// 110. 平衡二叉树
// https://leetcode.cn/problems/balanced-binary-tree/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(const string& val) : val(stoi(val)), left(nullptr), right(nullptr) {}
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
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

        if (nodes[i + 1] != "null")
        {
            cur->right = new TreeNode(nodes[i + 1]);
            que.push(cur->right);
        }
    }

    return root;
}

int treeDepth(TreeNode* cur, int depth)
{
    if (!cur) return depth - 1;

    int dL = treeDepth(cur->left, depth + 1);
    int dR = treeDepth(cur->right, depth + 1);
    cout << dL << " " << dR << endl;
    if (abs(dL - dR) > 1) return -1;

    return max(dL, dR);
}

bool isBalanced(TreeNode* root)
{
    return treeDepth(root, 1) != -1;
}

int main()
{
    int n;
    cin >> n;
    vector<string> nodes(n);

    for (string& node: nodes) cin >> node;
    TreeNode* root = createTree(nodes);

    cout << isBalanced(root) << endl;
    return 0;
}