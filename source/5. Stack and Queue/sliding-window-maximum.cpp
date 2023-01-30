// Created by Ashechol on 2023/1/29.
// 239. 滑动窗口最大值

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector<int> MaxValue(vector<int> nums, int k)
{
    deque<int> dq;
    vector<int> res;

    for (int i = 0; i < k; i++)
    {
        while (!dq.empty() && nums[i] > dq.back())
            dq.pop_back();
        dq.push_back(nums[i]);
    }
    res.push_back(dq.front());

    for (int i = k; i < nums.size(); i++)
    {
        while (!dq.empty() && nums[i] > dq.back())
            dq.pop_back();
        dq.push_back(nums[i]);

        if (nums[i - k] == dq.front())
            dq.pop_front();

        res.push_back(dq.front());
    }

    return res;
}

int main()
{
    int n = 0, k = 0;
    cin >> n >> k;

    vector<int> nums(n);

    for (int& num: nums) cin >> num;

    vector<int> res = MaxValue(nums, k);

    for (int num: res) cout << num << " ";
    cout << "\b\n";

    return 0;
}