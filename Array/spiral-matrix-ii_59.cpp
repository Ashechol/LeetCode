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
    vector<vector<int>> matrix(n);
    int value = 1;
    int l = 0, r = n - 1;
    int t = 0, d = n - 1;
    int i = 0, j = 0;

    for (vector<int>& row: matrix)
        row.resize(n);

    while (value <= n * n)
    {
        if (i == t && j == l)
        {
            for (; j <= r; j++)
                matrix[i][j] = value++;
            j--;
            i++;
            t++;
        }
        else if (i == t && j == r)
        {
            for (; i <= d; i++)
                matrix[i][j] = value++;
            i--;
            j--;
            r--;
        }
        else if (i == d && j == r)
        {
            for (; j >= l; j--)
                matrix[i][j] = value++;
            j++;
            i--;
            d--;
        }
        else if (i == d && j == l)
        {
            for (; i >= t; i--)
                matrix[i][j] = value++;
            i++;
            j++;
            l++;
        }
    }
    return matrix;
}
