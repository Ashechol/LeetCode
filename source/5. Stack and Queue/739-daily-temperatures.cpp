// Created by Ashechol on 2023/3/7.
// 739. 每日温度
// https://leetcode.cn/problems/daily-temperatures/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures)
{
    stack<int> stk;
    vector<int> res(temperatures.size(), 0);
    stk.push(0);

    for (int i = 1; i < temperatures.size(); i++)
    {
        int ind = stk.top();
        while (!stk.empty() && temperatures[ind] < temperatures[i])
        {
            res[ind] = i - ind;
            stk.pop();
            if (!stk.empty()) ind = stk.top();
        }
        stk.push(i);
    }

    return res;
}

int main()
{
    vector<int> temperatures;

    int tmp;
    while (cin >> tmp)
    {
        temperatures.emplace_back(tmp);
        if (cin.get() == '\n')
            break;
    }

    vector<int> res = dailyTemperatures(temperatures);

    for (int i = 0; i < res.size(); i++)
        cout << res[i] << "\n "[i != res.size()-1];
    return 0;
}
