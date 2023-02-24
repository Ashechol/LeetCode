// Created by Ashechol on 2023/2/24.
// 322. 零钱兑换
// https://leetcode.cn/problems/coin-change/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int coinChange(vector<int>& coins, int amount)
{
    if (amount == 0) return 0;

    vector<int> dp(amount+1, INT_MAX);
    dp[0] = 0;

    for (int& coin: coins)
    {
        for (int i = coin; i <= amount; i++)
        {
            if (dp[i-coin] != INT_MAX)
                dp[i] = min(dp[i-coin] + 1, dp[i]);
        }
    }

    return dp[amount] == INT_MAX ? -1 : dp[amount];
}

int main()
{
    int n, amount;
    cin >> n >> amount;

    vector<int> coins(n);
    for (int& coin: coins) cin >> coin;

    cout << coinChange(coins, amount) << endl;
    return 0;
}
