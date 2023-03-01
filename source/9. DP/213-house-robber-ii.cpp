// Created by Ashechol on 2023/3/1.
// 213. 打家劫舍 II
// https://leetcode.cn/problems/house-robber-ii/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int rob(vector<int>& nums)
{
    if (nums.size() == 1) return nums[0];

    vector<int> dp(2);

    dp[0] = 0; dp[1] = nums[0];
    for (int i = 1; i < nums.size() - 1; i++)
    {
        int tmp = max(dp[1], dp[0] + nums[i]);
        dp[0] = dp[1]; dp[1] = tmp;
    }
    int res1 = dp[1];

    dp[0] = 0; dp[1] = nums[1];
    for (int i = 2; i < nums.size(); i++)
    {
        int tmp = max(dp[1], dp[0] + nums[i]);
        dp[0] = dp[1]; dp[1] = tmp;
    }
    int res2 = dp[1];

    return max(res1, res2);
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int& num: nums) cin >> num;

    cout << rob(nums) << endl;
    return 0;
}
