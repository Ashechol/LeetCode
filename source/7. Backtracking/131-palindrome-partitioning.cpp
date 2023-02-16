// Created by Ashechol on 2023/2/16.
// 131. 分割回文串
// https://leetcode.cn/problems/palindrome-partitioning/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<vector<string>> res;
vector<string> path;
vector<vector<int>> record;

int check(string s, int bg, int ed)
{
    if (record[bg][ed] != 0)
        return record[bg][ed];

    for (int i = bg, j = ed; i < j; i++, j--)
    {
        if (s[i] != s[j])
        {
            record[bg][ed] = 2;
            return 2;
        }
        if (s[i] == s[j] && record[i+1][j-1] == 1)
        {
            record[bg][ed] = 1;
            return 1;
        }
    }
    record[bg][ed] = 1;
    return 1;
}

void dfs(string& s, int bg)
{
    if (bg == s.size())
    {
        res.emplace_back(path);
        return;
    }


    for (int i = bg; i < s.size(); i++)
    {
        if (check(s, bg, i) == 1)
        {
            path.emplace_back(s.substr(bg, i-bg+1));
            dfs(s, i+1);
            path.pop_back();
        }
    }
}

int main()
{
    string s;
    cin >> s;

    record.resize(s.size(),vector<int>(s.size(), 0));

    dfs(s, 0);
    for (const vector<string>& ans: res)
    {
        for (const string& subStr: ans)
            cout << subStr << " ";
        cout << '\b' << endl;
    }

    return 0;
}
