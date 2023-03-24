//
// Created by Ashechol on 2023/3/23.
//

#include <iostream>
#include <queue>
#include <cmath>
#include "LeetCode.h"

using namespace std;

int calSum(int cnt)
{
    int sum = 0;
    for (int i = 1; i <= cnt; ++i)
        sum += i;
    return sum;
}

TreeNode* fun(TreeNode* root)
{
    int evenCnt = 0, cnt = 0, sum = 0;
    queue<TreeNode*> que;
    if (root) que.push(root);
    int layer = 0;
    while (!que.empty())
    {
        int size = que.size();

        for (int i = 0; i < size; ++i)
        {
            TreeNode* cur = que.front(); que.pop();
            ++cnt;
            if (layer % 2 == 0) ++evenCnt;
            if (cur->left) que.push(cur->left);
            if (cur->right) que.push(cur->right);
        }
        ++layer;
    }
    int target = ceil((float) calSum(cnt) / 2.f);
    vector<int> eoHash(cnt + 1, 0);
    for (int i = 1; i <= evenCnt - 1; ++i)
    {
        eoHash[i] = 1;
        sum += i;
    }
    if (eoHash[target - sum] == 1) return nullptr;
    eoHash[target - sum] = 1;
    vector<int> even, odd;
    for (int i = 1; i <= cnt; ++i)
    {
        if (eoHash[i])
            even.emplace_back(i);
        else
            odd.emplace_back(i);
    }

    que.push(root);
    int e = 0, o = 0;
    while (!que.empty())
    {
        int size = que.size();
        for (int i = 0; i < size; ++i)
        {
            TreeNode* cur = que.front(); que.pop();
            cur->val = even[e++];
            if (cur->left) que.push(cur->left);
            if (cur->right) que.push(cur->right);
        }

        size = que.size();
        for (int i = 0; i < size; ++i)
        {
            TreeNode* cur = que.front(); que.pop();
            cur->val = odd[o++];
            if (cur->left) que.push(cur->left);
            if (cur->right) que.push(cur->right);
        }
    }

    return root;
}

int main()
{
    int n;
    cin >> n;
    vector<string> nodes(n);
    for (string& val: nodes) cin >> val;
    TreeNode* root = TreeNode::createTree(nodes);
    root = fun(root);

    TreeNode::coutTree(root);
    return 0;
}
