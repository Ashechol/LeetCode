// Created by Ashechol on 2023/2/20.
// 376. 摆动序列
// https://leetcode.cn/problems/wiggle-subsequence/

#include <iostream>
#include <vector>

using namespace std;

int wiggleMaxLength(vector<int>& nums)
{
    if (nums.size() <= 1) return nums.size();
    int cnt = 1;
    int preDiff = 0;
    int curDiff = 0;

    for (int i = 0; i < nums.size() - 1; i++)
    {
        curDiff = nums[i+1] - nums[i];

        if ((preDiff <= 0 && curDiff > 0) || (preDiff >= 0 && curDiff < 0))
        {
            preDiff = curDiff;
            cnt++;
        }
    }
    return cnt;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int& val: nums) cin >> val;

    int res = wiggleMaxLength(nums);
    cout << res << endl;
    return 0;
}
