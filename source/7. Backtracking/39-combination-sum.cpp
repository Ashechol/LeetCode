// Created by Ashechol on 2023/2/16.
// 39. 组合总和
// https://leetcode.cn/problems/combination-sum/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> res;
vector<int> path;
int sum;

void dfs(vector<int>& nums, int bg, int target)
{
    if (sum == target)
    {
        res.emplace_back(path);
        return;
    }

    for (int i = bg; i < nums.size() && sum + nums[i] <= target; i++)
    {
        path.emplace_back(nums[i]);
        sum += nums[i];
        dfs(nums, i, target);
        path.pop_back();
        sum -= nums[i];
    }
}

int main()
{
    int n, target;
    cin >> n >> target;
    vector<int> nums(n);

    for (int& num: nums) cin >> num;

    sort(nums.begin(), nums.end());
    dfs(nums, 0, target);

    for (const vector<int>& ans: res)
    {
        for (int num: ans)
            cout << num << " ";
        cout << '\b' << endl;
    }

    return 0;
}
