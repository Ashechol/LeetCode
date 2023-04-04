// Created by hanchao.gong on 2023/4/4.
// 56. 合并区间
// https://leetcode.cn/problems/merge-intervals/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals)
{
    vector<vector<int>> res;
    sort(intervals.begin(), intervals.end());

    res.emplace_back(intervals[0]);
    for (int i = 1; i < intervals.size(); ++i)
    {
        if (intervals[i][0] > res.back()[1])
            res.emplace_back(intervals[i]);
        else if (intervals[i][1] > res.back()[1])
            res.back()[1] = intervals[i][1];
    }

    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> intervals;

    int t1, t2;
    while (n--)
    {
        while (cin >> t1 >> t2)
        {
            intervals.emplace_back(vector<int>{t1, t2});
            if (cin.get() == '\n') break;
        }
    }

    vector<vector<int>> res = merge(intervals);
    for (auto & re : res)
        cout << re[0] << " " << re[1] << endl;

    return 0;
}