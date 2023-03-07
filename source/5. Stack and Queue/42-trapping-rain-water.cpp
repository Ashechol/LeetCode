// Created by Ashechol on 2023/3/5.
// 42. 接雨水
// https://leetcode.cn/problems/trapping-rain-water/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int trap(vector<int>& height)
{
    stack<int> stk;
    int sum = 0;
    stk.push(0);
    for (int i = 1; i < height.size(); i++)
    {
        int ind = stk.top();
        while (!stk.empty() && height[i] >= height[ind])
        {
            int mid = ind; stk.pop();
            if (!stk.empty())
            {
                ind = stk.top();
                sum += (min(height[ind], height[i]) - height[mid]) * (i - ind - 1);
            }
        }
        stk.push(i);
    }

    return sum;
}

int main()
{
    vector<int> height;

    int tmp;
    while (cin >> tmp)
    {
        height.emplace_back(tmp);
        if (cin.get() == '\n') break;
    }

    cout << trap(height) << endl;
    return 0;
}
