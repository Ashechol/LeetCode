// Created by Ashechol on 2022/9/17.
// 209. 长度最小的子数组
// 题目链接：https://leetcode.cn/problems/minimum-size-subarray-sum/
// 题解链接：https://www.wolai.com/ktot9KqKvRKWvcJT5s15D3#fEER5bwC3njFgfgzTCvrHj

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int minSubArrayLen(int target, vector<int>& nums);

int main()
{
    int n, target;

    cin >> n >> target;

    vector<int> nums(n);

    for (int& num: nums) cin >> num;

    cout << minSubArrayLen(target, nums);

    return 0;
}

int minSubArrayLen_que(int target, vector<int>& nums)
{
    queue<int> que;
    int sum = 0;
    int minLen = INT32_MAX;

    for (int& num: nums)
    {
        sum += num;
        que.push(num);

        while (sum >= target)
        {
            if (minLen > que.size()) minLen = (int) que.size();

            sum -= que.front();
            que.pop();
        }
    }

    return minLen == INT32_MAX ? 0 : minLen;
}

int minSubArrayLen(int target, vector<int>& nums)
{
    int sum = 0;
    int minLen = INT32_MAX;

    for (int l = 0, r = 0; r < nums.size(); r++)
    {
        sum += nums[r];

        while (sum >= target)
        {
            // r - l + 1 因为 [l, r]
            if (minLen > r - l + 1) minLen = r - l + 1;

            sum -= nums[l++];
        }
    }

    // 另外一种循环写法
    // for (int l = 0, r = 0; r < nums.size() || sum >= target;)
    // {
    //     if (sum >= target)
    //     {
    // [l, r)
    //         if (minLen > r - l) minLen = r - l;
    //
    //         sum -= nums[l++];
    //     }
    //     else if (r < nums.size())
    //         sum += nums[r++];
    // }

    return minLen == INT32_MAX ? 0 : minLen;
}

