// Created by Ashechol on 2023/2/20.
// 70. 爬楼梯
// https://leetcode.cn/problems/climbing-stairs/

#include <iostream>
#include <vector>

using namespace std;

int climbStairs(int n)
{
    if (n == 1) return 1;

    vector<int> dp(n+1);
    dp[1] = 1; dp[2] = 2;

    for (int i = 3; i <= n; i++)
        dp[i] = dp[i-1] + dp[i-2];

    return dp[n];
}

int main()
{
    int n;
    cin >> n;
    cout << climbStairs(n) << endl;
    return 0;
}