// Created by Ashechol on 2023/2/14.
// 216. 组合总和 III
// https://leetcode.cn/problems/combination-sum-iii/

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> res;
vector<int> path;
int sum;
void dfs(int bg, int k, int n)
{
    if (path.size() == k)
    {
        if (sum == n) res.emplace_back(path);
        return;
    }

    if (bg > n - sum) return;

    for (int i = bg; i <= 9; i++)
    {
        path.emplace_back(i);
        sum += i;
        dfs(i + 1, k, n);
        sum -= i;
        path.pop_back();
    }
}

int main()
{
    int n, k;
    cin >> k >> n;

    dfs(1, k, n);

    for (const vector<int>& ans: res)
    {
        for (int val: ans)
            cout << val << " ";
        cout << "\b" << endl;
    }

    return 0;
}
