// Created by Ashechol on 2023/2/18.
// 47. 全排列 II
// https://leetcode.cn/problems/permutations-ii/description/

#include <iostream>
#include <vector>

using namespace std;

vector<bool> usedIndex;
void dfs(vector<int>& nums,vector<vector<int>>& res, vector<int>& path)
{
    if (path.size() == nums.size())
    {
        res.emplace_back(path);
        return;
    }

    vector<bool> usedVal(25, false);
    for (int i = 0; i < nums.size(); i++)
    {
        if (usedIndex[i] || usedVal[nums[i]+10])
            continue;

        path.emplace_back(nums[i]);
        usedIndex[i] = true;
        usedVal[nums[i]+10] = true;
        dfs(nums, res, path);
        usedIndex[i] = false;
        path.pop_back();
    }
}
vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> path;
    usedIndex.resize(nums.size(), false);
    dfs(nums, res, path);

    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int& num: nums) cin >> num;

    vector<vector<int>> res = permuteUnique(nums);

    for (const vector<int>& ans: res)
    {
        for (int num: ans)
            cout << num << " ";
        cout << '\b' << endl;
    }

    return 0;
}