// Created by Ashechol on 2023/2/18.
// 491. 递增子序列
// https://leetcode.cn/problems/non-decreasing-subsequences/

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

void dfs(vector<int>& nums, int bg, vector<vector<int>>& res, vector<int>& path)
{
    if (path.size() >= 2)
        res.emplace_back(path);

    if (bg == nums.size())
        return;

    vector<bool> used(205, false);
    for (int i = bg; i < nums.size(); i++)
    {
        if (used[nums[i]+100])
            continue;

        if (path.empty() || nums[i] >= path.back())
        {
            path.emplace_back(nums[i]);
            used[nums[i]+100] = true;
            dfs(nums, i+1, res, path);
            path.pop_back();
        }
    }
}

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int& num: nums) cin >> num;

    vector<vector<int>> res;
    vector<int> path;
    dfs(nums, 0, res, path);

    for (const vector<int>& ans: res)
    {
        for (int num: ans)
            cout << num << " ";
        cout << '\b' << endl;
    }

    return 0;
}
