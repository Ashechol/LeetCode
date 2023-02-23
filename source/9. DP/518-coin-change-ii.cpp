// Created by Ashechol on 2023/2/23.
// 518. 零钱兑换 II
// https://leetcode.cn/problems/coin-change-ii/

#include <iostream>
#include <vector>

using namespace std;

int change(int amount, vector<int>& coins)
{
    vector<int> dp(amount+1, 0);
    dp[0] = 1;
    for (int& coin: coins)
    {
        for (int i = coin; i <= amount; i++)
        {
            dp[i] = dp[i] + dp[i-coin];
        }
    }

    return dp[amount];
}

int main()
{
    int n, amount;
    cin >> n >> amount;
    vector<int> coins(n);

    for (int& coin: coins) cin >> coin;

    cout << change(amount, coins) << endl;
    return 0;
}
