// Created by Ashechol on 2023/2/18.
// 332. 重新安排行程
// https://leetcode.cn/problems/reconstruct-itinerary/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>

using namespace std;

typedef unordered_map<string, map<string, int>> Route;
bool dfs(Route& route, vector<string>& res, int remain)
{
    if (remain == 0)
        return true;

    // 键值不能修改，所以这里的 pair 引用键值是 const string
    for (pair<const string, int>& to: route[res.back()])
    {
        if (to.second == 0) continue;

        to.second--;
        res.emplace_back(to.first);
        if (dfs(route, res, remain-1))
            return true;
        res.pop_back();
        to.second++;
    }
    return false;
}
vector<string> findItinerary(vector<vector<string>>& tickets)
{
    vector<string> res;
    Route route;

    for (const vector<string>& ticket: tickets)
        route[ticket[0]][ticket[1]]++;

    res.emplace_back("JFK");
    dfs(route, res, tickets.size());

    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<string>> tickets(n, vector<string>(2));

    for (vector<string>& ticket: tickets)
        for (string& place: ticket)
            cin >> place;

    vector<string> res = findItinerary(tickets);
    for (const string& place: res)
        cout << place << " ";
    cout << '\b' << endl;

    return 0;
}