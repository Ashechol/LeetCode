// Created by Ashechol on 2023/2/18.
// 78. 子集
// https://leetcode.cn/problems/subsets/

#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<int>& nums, int bg, vector<vector<int>>& res, vector<int>& path)
{
    res.emplace_back(path);

    if (bg == nums.size())
        return;

    for (int i = bg; i < nums.size(); i++)
    {
        path.emplace_back(nums[i]);
        dfs(nums, i+1, res, path);
        path.pop_back();
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
