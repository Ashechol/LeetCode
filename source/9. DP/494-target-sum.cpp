// Created by Ashechol on 2023/2/21.
// 494. 目标和
// https://leetcode.cn/problems/target-sum/

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int findTargetSumWays(vector<int>& nums, int target)
{
    int sum = accumulate(nums.begin(), nums.end(), 0);

    if (target > sum || (target + sum) % 2 == 1)
        return 0;

    int bagSize = (target + sum) >> 1;
    vector<int> dp(bagSize + 1, 0);
    dp[0] = 1;
    for (int& num: nums)
    {
        for (int i = bagSize; i >= num; i--)
        {
            dp[i] = dp[i] + dp[i-num];
        }
    }

    return dp[bagSize];
}

int main()
{
    int n, t;
    cin >> n >> t;
    vector<int> nums(n);
    for (int& num: nums) cin >> num;
    cout << findTargetSumWays(nums, t) << endl;
    return 0;
}