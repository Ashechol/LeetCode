// Created by Ashechol on 2023/2/14.
// 77. 组合
// https://leetcode.cn/problems/combinations/

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> ans;
vector<int> path;
void dfs(int bg, int n, int k)
{
    if (path.size() == k)
    {
        ans.emplace_back(path);
        return;
    }

    if (n - bg + 1 < k - path.size()) return;

    for (int i = bg; i <= n; i++)
    {
        path.emplace_back(i);
        dfs(i + 1, n, k);
        path.pop_back();
    }
}

vector<vector<int>> combine(int n, int k)
{
    dfs(1, n, k);
    return ans;
}

int main()
{
    int n, k;
    cin >> n >> k;

    vector<vector<int>> res = combine(n, k);

    for (const vector<int>& nums: res)
    {
        for (int val: nums)
            cout << val << " ";
        cout << "\b" << endl;
    }

    return 0;
}
