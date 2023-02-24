// Created by Ashechol on 2023/2/24.
// 279. 完全平方数
// https://leetcode.cn/problems/perfect-squares/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int numSquares(int n)
{
    vector<int> dp(n+1, INT_MAX);
    dp[0] = 0;
    int sqrtN = (int) sqrt(n);

    for (int i = 1; i <= sqrtN; i++)
    {
        int square = i * i;
        for (int j = square; j <= n; j++)
        {
            if (dp[j-square] != INT_MAX)
                dp[j] = min(dp[j], dp[j-square] + 1);
        }
    }

    return dp[n];
}

int main()
{
    int n;
    cin >> n;
    cout << numSquares(n) << endl;
    return 0;
}
