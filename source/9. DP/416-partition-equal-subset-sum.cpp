// Created by Ashechol on 2023/2/21.
// 416. 分割等和子集
// https://leetcode.cn/problems/partition-equal-subset-sum/

#include <iostream>
#include <vector>

using namespace std;

bool canPartition(vector<int>& nums)
{
    int sum = 0;
    for (int& val: nums) sum += val;
    if (sum % 2 != 0) return false;

    int m = (sum >> 1);
    vector<int> dp(m+1, 0);

    for (int num : nums)
    {
        for (int j = m; j >= num; j--)
        {
            dp[j] = max(dp[j], dp[j-num] + num);
            if (dp[j] == m)
                return true;
        }
    }

    return false;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);

    for (int& val: nums) cin >> val;

    cout << canPartition(nums) << endl;
    return 0;
}