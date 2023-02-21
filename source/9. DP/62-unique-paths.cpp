// Created by Ashechol on 2023/2/20.
// 62. 不同路径
// https://leetcode.cn/problems/unique-paths/

#include <iostream>
#include <vector>

using namespace std;

int uniquePaths(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, 0));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i > 0 && j > 0)
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            else
                dp[i][j] = 1;

            // cout << i << " " << j << " " << dp[i][j] << endl;
        }
    }

    return dp[m-1][n-1];
}

int main()
{
    int m, n;
    cin >> m >> n;

    cout << uniquePaths(m, n) << endl;
    return 0;
}
