// Created by Ashechol on 2023/3/1.
// 198. 打家劫舍
// https://leetcode.cn/problems/house-robber/

#include <iostream>
#include <vector>

using namespace std;

int rob(vector<int>& nums)
{
    vector<int> dp(nums.size()+1);
    dp[0] = 0; dp[1] = nums[0];

    for (int i = 1; i < nums.size(); i++)
    {
        dp[i+1] = max(dp[i], dp[i-1] + nums[i]);
    }

    return dp.back();
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
