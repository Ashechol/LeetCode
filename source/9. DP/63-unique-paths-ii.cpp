// Created by Ashechol on 2023/2/20.
// 63. 不同路径 II
// https://leetcode.cn/problems/unique-paths-ii/

#include <iostream>
#include <vector>

using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
{
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();

    if (obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1)
        return 0;

    vector<vector<int>> dp(m, vector<int>(n, 1));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (obstacleGrid[i][j] == 1)
                dp[i][j] = 0;
            else if (i > 0 && j > 0)
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            else if (i > 0)
                dp[i][j] = dp[i-1][j];
            else if (j > 0)
                dp[i][j] = dp[i][j-1];
        }
    }

    return dp[m-1][n-1];
}

int main()
{
    int m, n;
    cin >> m >> n;

    vector<vector<int>> grid(m, vector<int>(n));
    for (vector<int>& row: grid)
        for (int& val: row)
            cin >> val;

    cout << uniquePathsWithObstacles(grid) << endl;
    return 0;
}
