// Created by Ashechol on 2023/2/18.
// 46. 全排列
// https://leetcode.cn/problems/permutations/

#include <iostream>
#include <vector>

using namespace std;

vector<bool> used(25, false);
void dfs(vector<int>& nums, vector<vector<int>>& res, vector<int>& path)
{
    if (path.size() == nums.size())
    {
        res.emplace_back(path);
        return;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (used[nums[i]])
            continue;

        path.emplace_back(nums[i]);
        used[nums[i]] = true;
        dfs(nums, res, path);
        used[nums[i]] = false;
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

    dfs(nums, res, path);

    for (const vector<int>& ans: res)
    {
        for (int num: ans)
            cout << num << " ";
        cout << '\b' << endl;
    }

    return 0;
}
