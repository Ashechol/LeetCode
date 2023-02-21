// Created by Ashechol on 2023/2/21.
// 1049. 最后一块石头的重量 II
// https://leetcode.cn/problems/last-stone-weight-ii/

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int lastStoneWeightII(vector<int>& stones)
{
    int sum = accumulate(stones.begin(), stones.end(), 0);
    int target = sum >> 1;
    vector<int> dp(target + 1, 0);

    for (int stone : stones)
    {
        for (int j = target; j >= stone; j--)
            dp[j] = max(dp[j], dp[j-stone] + stone);
    }

    return sum - dp[target] * 2;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int& num: nums) cin >> num;

    cout << lastStoneWeightII(nums) << endl;
    return 0;
}