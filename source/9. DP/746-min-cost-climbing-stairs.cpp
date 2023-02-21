// Created by Ashechol on 2023/2/20.
// 746. 使用最小花费爬楼梯
// https://leetcode.cn/problems/min-cost-climbing-stairs/

#include <iostream>
#include <vector>

using namespace std;

int minCostClimbingStairs(vector<int>& cost)
{
    int dp[2] = {cost[0], cost[1]};

    for (int i = 2; i < cost.size(); i++)
    {
        int sum = min(dp[0], dp[1]) + cost[i];
        dp[0] = dp[1];
        dp[1] = sum;
    }

    return min(dp[0], dp[1]);
}

int main()
{
    int n;
    cin >> n;
    vector<int> cost(n);
    for (int& val: cost) cin >> val;

    cout << minCostClimbingStairs(cost) << endl;
    return 0;
}
