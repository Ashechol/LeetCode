// Created by Ashechol on 2023/3/2.
// 337. 打家劫舍 III
// https://leetcode.cn/problems/house-robber-iii/

#include <iostream>
#include <vector>
#include <array>
#include <queue>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(const string& node) : val(stoi(node)), left(nullptr), right(nullptr) {}
};

vector<int> traversal(TreeNode* cur)
{
    if (!cur) return {0, 0};

    vector<int> left = traversal(cur->left);
    vector<int> right = traversal(cur->right);

    int selectCur = left[0] + right[0] + cur->val;
    int skipCur = max(left[0], left[1]) + max(right[0], right[1]);

    return {skipCur, selectCur};
}

int rob(TreeNode* root)
{
    vector<int> res = traversal(root);
    return max(res[0], res[1]);
}

TreeNode* createTree(vector<string> nodes)
{
    if (nodes.empty()) return nullptr;
    if (nodes.size() % 2 == 0) nodes.emplace_back("null");

    auto root = new TreeNode(nodes[0]);
    queue<TreeNode*> que; que.push(root);

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

    cout << rob(root) << endl;
    return 0;
}