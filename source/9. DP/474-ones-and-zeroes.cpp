// Created by Ashechol on 2023/2/22.
// 474. 一和零
// https://leetcode.cn/problems/ones-and-zeroes/

#include <iostream>
#include <vector>

using namespace std;

int findMaxForm(vector<string>& strs, int m, int n)
{
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

    for (string& str: strs)
    {
        int cnt0 = 0, cnt1 = 0;
        for (char& c: str) c == '0' ? cnt0++ : cnt1++;

        for (int i = m; i >= cnt0; i--)
        {
            for (int j = n; j >= cnt1; j--)
                dp[i][j] = max(dp[i][j], dp[i-cnt0][j-cnt1] + 1);
        }
    }

    return dp[m][n];
}

int main()
{
    int m, n;
    cin >> n;
    vector<string> str(n);
    cin >> m >> n;

    for (string& s: str) cin >> s;

    cout << findMaxForm(str, m, n) << endl;
    return 0;
}
