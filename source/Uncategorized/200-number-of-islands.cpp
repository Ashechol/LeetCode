// Created by Ashechol on 2023/2/27.
// 200. 岛屿数量
// https://leetcode.cn/problems/number-of-islands/description/

#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<char>>& grid, int row, int col)
{
    if (row >= grid.size() || row < 0) return;
    if (col >= grid[0].size() || col < 0) return;
    if (grid[row][col] == '0') return;

    grid[row][col] = '0';
    dfs(grid, row+1, col);
    dfs(grid, row-1, col);
    dfs(grid, row, col+1);
    dfs(grid, row, col-1);
}

int numIslands(vector<vector<char>>& grid)
{
    int cnt = 0;

    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (grid[i][j] == '1')
            {
                dfs(grid, i, j);
                cnt++;
            }
        }
    }

    return cnt;
}

int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<char>> grid(m, vector<char>(n, 0));
    for (vector<char>& row: grid)
        for (char& val: row)
            cin >> val;

    cout << numIslands(grid) << endl;
    
    return 0;
}
