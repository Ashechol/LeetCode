// Created by Ashechol on 2023/2/3.
// 116. 填充每个节点的下一个右侧节点指针
// https://leetcode.cn/problems/populating-next-right-pointers-in-each-node/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node
{
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node(int x) : val(x), left(nullptr), right(nullptr), next(nullptr) {}
};

Node* createTree(vector<string> nodes)
{
    if (nodes.empty()) return nullptr;
    if (nodes.size() % 2 == 0) nodes.emplace_back("null");

    Node* root = new Node(stoi(nodes[0]));
    queue<Node*> que;
    que.push(root);

    for (int i = 1; i < nodes.size(); i += 2)
    {
        Node* cur = que.front();
        que.pop();

        if (nodes[i] != "null")
        {
            cur->left = new Node(stoi(nodes[i]));
            que.push(cur->left);
        }

        if (nodes[i + 1] != "null")
        {
            cur->right = new Node(stoi(nodes[i + 1]));
            que.push(cur->right);
        }
    }

    return root;
}

Node* bfs(Node* root)
{
    queue<Node*> que;
    if (root) que.push(root);

    while (!que.empty())
    {
        int size = que.size();

        for (int i = 0; i < size; i++)
        {
            Node* cur = que.front();
            que.pop();

            if (i < size - 1)
                cur->next = que.front();

            if (cur->left) que.push(cur->left);
            if (cur->right) que.push(cur->right);
        }
    }

    return root;
}

Node* connect(Node* root)
{
    if (!root) return nullptr;

    Node* level = root;

    while (level->left)
    {
        Node* cur = level;
        while (cur)
        {
            if (cur->left && cur->right)
                cur->left->next = cur->right;
            if (cur->next && cur->right && cur->next->left)
                cur->right->next = cur->next->left;

            cur = cur->next;
        }

        level = level->left;
    }
    return root;
}

int main()
{
    int n;
    cin >> n;
    vector<string> nodes(n);

    for (string& node: nodes) cin >> node;

    Node* root = createTree(nodes);
    root = connect(root);

    Node* level = root;
    while (level)
    {
        Node* cur = level;

        while (cur)
        {
            cout << cur->val << " ";
            cur = cur->next;
        }

        cout << "# ";

        level = level->left;
    }

    cout << "\b\n";
}