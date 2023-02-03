// Created by Ashechol on 2023/2/2.
// 429. N 叉树的层序遍历
// https://leetcode.cn/problems/n-ary-tree-level-order-traversal/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node
{
    int val;
    vector<Node*> children;

    Node(int x) : val(x) {}
    Node(int x, vector<Node*> _children) : val(x), children(children) {}
};

vector<vector<int>> solution(Node* root)
{
    vector<vector<int>> res;
    queue<Node*> que;

    if (root) que.push(root);

    while (!que.empty())
    {
        int size = que.size();
        vector<int> val;

        while (size--)
        {
            Node* cur = que.front();
            que.pop();

            val.emplace_back(cur->val);

            for (Node* c: cur->children)
                que.push(c);
        }

        res.emplace_back(val);
    }

    return res;
}

int main()
{
    Node* root = new Node(1);
    Node* c1 = new Node(3);
    Node* c2 = new Node(2);
    Node* c3 = new Node(4);
    Node* c4 = new Node(5);
    Node* c5 = new Node(6);
    root->children = vector<Node*>{c1, c2, c3};
    c1->children = vector<Node*>{c4, c5};

    vector<vector<int>> res = solution(root);

    for (vector<int> val: res)
    {
        for (int v: val)
            cout << v << " ";
        cout << "\b\n";
    }

    return 0;
}