// Created by Ashechol on 2023/2/18.
// 51. N 皇后
// https://leetcode.cn/problems/n-queens/

#include <iostream>
#include <vector>

using namespace std;

bool checkQueen(vector<string>& board, int row, int col)
{
    int n = board.size();
    for (int i = row; i >= 0; i--)
        if (board[i][col] == 'Q') return true;

    int i = row, j = col;
    while (i >= 0 && j >= 0)
        if (board[i--][j--] == 'Q') return true;

    i = row; j = col;
    while (i >= 0 && j < n)
        if (board[i--][j++] == 'Q') return true;

    return false;
}

void dfs(vector<string>& board, int row, vector<vector<string>>& res)
{
    if (row == board.size())
    {
        res.emplace_back(board);
        return;
    }

    for (int i = 0; i < board.size(); i++)
    {
        if (checkQueen(board, row, i))
            continue;

        board[row][i] = 'Q';
        dfs(board, row+1, res);
        board[row][i] = '.';
    }
}

int main()
{
    int n;
    cin >> n;

    vector<string> board(n, string(n, '.'));
    vector<vector<string>> res;
    dfs(board, 0, res);
    for (const vector<string>& ans: res)
    {
        for (const string& s: ans)
            cout << s << endl;
        cout << '\b' << endl;
    }

    return 0;
}
