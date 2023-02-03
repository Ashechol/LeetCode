// Created by Ashechol on 2023/2/3.
// 117. 填充每个节点的下一个右侧节点指针 II
// https://leetcode.cn/problems/populating-next-right-pointers-in-each-node-ii/

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

void connect(Node* root)
{
    if (!root) return;

    Node* cur = root;
    Node* dummy = new Node(0);

    while (cur)
    {
        dummy->next = nullptr;
        Node* pre = dummy;

        while (cur)
        {
            cout << cur->val << " ";

            if (cur->left)
                pre = pre->next = cur->left;

            if (cur->right)
                pre = pre->next = cur->right;

            cur = cur->next;
        }

        cur = dummy->next;
        cout << "# ";
    }
    cout << "\b\n";
}

int main()
{
    int n;
    cin >> n;
    vector<string> nodes(n);

    for (string& node: nodes) cin >> node;
    Node* root = createTree(nodes);
    connect(root);

    return 0;
}