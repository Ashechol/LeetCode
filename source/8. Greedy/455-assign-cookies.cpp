// Created by Ashechol on 2023/2/19.
// 455. 分发饼干
// https://leetcode.cn/problems/assign-cookies/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findContentChildren(vector<int>& g, vector<int>& s)
{
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    int i = 0, j = 0, cnt = 0;
    while (i < g.size() && j < s.size())
    {
        if (g[i] <= s[j++])
        {
            cnt++;
            i++;
        }
    }

    return cnt;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> g(n), s(m);

    for (int& val: g) cin >> val;
    for (int& val: s) cin >> val;

    int res = findContentChildren(g, s);
    cout << res << endl;
    return 0;
}