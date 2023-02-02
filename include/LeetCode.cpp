// Created by Ashechol on 2023/2/1.
//

#include "LeetCode.h"
#include <queue>

using namespace std;

ListNode* ListNode::cinListNode(int n)
{
    auto* head = new ListNode();
    ListNode* p = head;

    cin >> head->val;

    for (int i = 1; i < n; i++)
    {
        int num;
        cin >> num;
        p->next = new ListNode(num);
        p = p->next;
    }

    return head;
}

ListNode* ListNode::cinListNodeCircle(int n, int pos)
{
    auto* head = new ListNode();
    ListNode* p = head;
    ListNode* tmp = nullptr;

    cin >> head->val;

    for (int i = 1; i < n; i++)
    {
        int num;
        cin >> num;
        p->next = new ListNode(num);

        if (i - 1 == pos)
            tmp = p;

        p = p->next;
    }
    p->next = tmp;
    return head;
}

TreeNode *TreeNode::createTree(vector<string> nodes)
{
    if (nodes.empty()) return nullptr;
    if (nodes.size() % 2 == 0)
        nodes.emplace_back("null");

    auto root = new TreeNode(stoi(nodes[0]));
    queue<TreeNode*> que;
    que.push(root);

    for (int i = 1; i < nodes.size(); i += 2)
    {
        TreeNode *node = que.front();

        if (nodes[i] != "null")
        {
            node->left = new TreeNode(stoi(nodes[i]));
            que.push(node->left);
        }

        if (nodes[i + 1] != "null")
        {
            node->right = new TreeNode(stoi(nodes[i + 1]));
            que.push(node->right);
        }

        que.pop();
    }

    return root;
}

TreeNode *TreeNode::createTreeCBT(const vector<string>& nodes)
{
    if (nodes.empty()) return nullptr;

    vector<TreeNode*> createdNodes;
    TreeNode* root;

    for (const string& node: nodes)
    {
        if (node != "null")
            createdNodes.emplace_back(new TreeNode(stoi(node)));
        else
            createdNodes.emplace_back(nullptr);
    }

    root = createdNodes[0];

    for (int i = 0; i * 2 + 2 < nodes.size(); i++)
    {
        if (createdNodes[i])
        {
            createdNodes[i]->left = createdNodes[i * 2 + 1];
            createdNodes[i]->right = createdNodes[i * 2 + 2];
        }
    }

    return root;
}
