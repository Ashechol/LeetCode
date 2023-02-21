// Created by Ashechol on 2023/2/20.
// 343. 整数拆分
// https://leetcode.cn/problems/integer-break/

#include <iostream>
#include <vector>

using namespace std;

int integerBreak(int n)
{
    vector<int> dp(n+1, 0);
    dp[2] = 1;
    for (int i = 3; i <= n; i++)
    {
        for (int j = 1; j <= (i >> 1); j++)
            dp[i] = max(dp[i], max(j * dp[i-j], (i-j)*j));
    }

    return dp[n];
}

int main()
{
    int n;
    cin >> n;
    cout << integerBreak(n) << endl;
    return 0;
}
