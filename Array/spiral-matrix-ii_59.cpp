// Created by Ashechol on 2022/9/19.
// 59. 螺旋矩阵 II
// 题目链接：https://leetcode.cn/problems/spiral-matrix-ii/
// 题解链接：https://www.wolai.com/fbYNcTLt1U2qr2DRdtTwpQ#6jj4vwhPzZ2ZtB6C77udJ2

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generateMatrix(int n);

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> matrix = generateMatrix(n);

    for (const vector<int>& row: matrix)
    {
        for(int num: row)
            cout << num << " ";

        cout << "\b\n";
    }

    return 0;
}

vector<vector<int>> generateMatrix(int n)
{
    vector<vector<int>> matrix(n, vector<int>(n,0));
    int value = 1;
    // 左右边界
    int l = 0, r = n - 1;
    // 上下边界
    int t = 0, d = n - 1;
    int i = 0, j = 0;

    while (value < n * n)
    {
        for (; j < r; j++)
            matrix[i][j] = value++;
        t++;

        for (; i < d; i++)
            matrix[i][j] = value++;
        r--;

        for (; j > l; j--)
            matrix[i][j] = value++;
        d--;

        for (; i > t; i--)
            matrix[i][j] = value++;
        l++;
    }
    cout << matrix[i][j] << endl;
    matrix[i][j] = value;

    return matrix;
}
