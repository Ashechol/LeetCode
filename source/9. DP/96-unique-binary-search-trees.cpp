// Created by Ashechol on 2023/2/20.
// 96. 不同的二叉搜索树
// https://leetcode.cn/problems/unique-binary-search-trees/

#include <iostream>
#include <vector>

using namespace std;

int numTrees(int n)
{
    vector<int> dp(n+1, 0);
    dp[0] = 1; dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
            dp[i] += dp[j] * dp[i-1-j];
    }

    return dp[n];
}

int main()
{
    int n;
    cin >> n;
    cout << numTrees(n) << endl;
    return 0;
}
