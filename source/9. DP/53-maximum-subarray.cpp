// Created by Ashechol on 2023/3/4.
// 53. 最大子数组和
// https://leetcode.cn/problems/maximum-subarray/

#include <iostream>
#include <vector>

using namespace std;

int maxSubArray(vector<int>& nums)
{
    int preMax = 0;
    int res = INT_MIN;

    for (int& num: nums)
    {
        preMax = max(preMax + num, num);
        res = max(preMax, res);
    }

    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int& num: nums) cin >> num;

    cout << maxSubArray(nums) << endl;
    return 0;
}
