// Created by Ashechol on 2023/2/28.
// 2363. 合并相似的物品
// https://leetcode.cn/problems/merge-similar-items/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<vector<int>> solution(vector<vector<int>>& items1, vector<vector<int>>& items2)
{
    vector<vector<int>> res;

    unordered_map<int, int> itemHash;

    for (vector<int>& item: items1) itemHash[item[0]] = item[1];
    for (vector<int>& item: items2) itemHash[item[0]] += item[1];

    // auto & [a, b] is structured binding declaration in C17
    for (auto & [a, b]: itemHash)
        res.push_back({a, b});

    sort(res.begin(), res.end());

    return res;
}

int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<int>> items1(m, vector<int>(2)), items2(n, vector<int>(2));
    for (vector<int>& item: items1) cin >> item[0] >> item[1];
    for (vector<int>& item: items2) cin >> item[0] >> item[1];

    vector<vector<int>> res = solution(items1, items2);

    for (vector<int>& ans: res)
        cout << ans[0] << " " << ans[1] << endl;

    return 0;
}
