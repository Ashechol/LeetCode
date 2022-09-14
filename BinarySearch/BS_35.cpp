// Created by Ashechol on 2022/9/13.
// 35. 搜索插入位置
// 题目链接：https://leetcode.cn/problems/search-insert-position/
// 题解：https://www.wolai.com/4d217ahiXiWYHtpT8yCXAV#67BW4epZH8c2HKdx5giTJi


#include <iostream>
#include <vector>

using namespace std;

int searchInsert(vector<int>& nums, int target);

int main()
{
    int n, target;
    cin >> n >> target;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) cin >> nums[i];

    cout << searchInsert(nums, target) << endl;

    return 0;
}

int searchInsert(vector<int>& nums, int target)
{
    int left{0}, right{ static_cast<int>(nums.size()) };

    while (left < right)
    {
        int mid = ((right - left) >> 1) + left;

        if (nums[mid] == target) return mid;
        if (nums[mid] > target) right = mid;
        if (nums[mid] < target) left = mid + 1;
    }

    return right; // 右开
}