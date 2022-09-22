// Created by Ashechol on 2022/9/20.
// 54. 螺旋矩阵
// 题目链接：https://leetcode.cn/problems/spiral-matrix/
// 题解链接：https://www.wolai.com/5s26EzN4YqhyfM9qkk2wMb#iPzytRdwnbUxc8BmXUYMBz

#include <iostream>
#include <vector>

using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix);

int main()
{
    int m, n;
    cin >> m >> n;

    vector<vector<int>> matrix(m, vector<int>(n));

    for (vector<int>& row: matrix)
        for (int& num: row)
            cin >> num;

    vector<int> nums = spiralOrder(matrix);

    for (int num: nums) cout << num << " ";
    cout << "\b\n";

    return 0;
}

vector<int> spiralOrder(vector<vector<int>>& matrix)
{
    vector<int> nums;

    int m = (int) matrix.size();
    int n = (int) matrix[0].size();

    int t = 0, d = m - 1;
    int l = 0, r = n - 1;
    int i = 0, j = 0;

    while (nums.size() < m * n - 1)
    {
        for (; j < r && nums.size() < m * n - 1; j++)
            nums.push_back(matrix[i][j]);
        t++;

        for (; i < d && nums.size() < m * n - 1; i++)
            nums.push_back(matrix[i][j]);
        r--;

        for (; j > l && nums.size() < m * n - 1; j--)
            nums.push_back(matrix[i][j]);
        d--;

        for (; i > t && nums.size() < m * n - 1; i--)
            nums.push_back(matrix[i][j]);
        l++;
    }

    nums.push_back(matrix[i][j]);

    return nums;
}
