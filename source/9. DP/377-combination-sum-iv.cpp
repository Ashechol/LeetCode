// Created by Ashechol on 2023/2/23.
// 377. 组合总和 Ⅳ
// https://leetcode.cn/problems/combination-sum-iv/

#include <iostream>
#include <vector>

using namespace std;

int combinationSum4(vector<int>& nums, int target)
{
    vector<int> dp(target+1, 0);
    dp[0] = 1;

    for (int i = 0; i <= target; i++)
    {
        for (int num : nums)
        {
            if (i - num >= 0 && dp[i] < INT_MAX - dp[i-num])
                dp[i] += dp[i-num];
        }
    }

    return dp[target];
}

int main()
{
    int n, target;
    cin >> n >> target;

    vector<int> nums(n);
    for (int& num: nums) cin >> num;

    cout << combinationSum4(nums, target) << endl;
    return 0;
}
