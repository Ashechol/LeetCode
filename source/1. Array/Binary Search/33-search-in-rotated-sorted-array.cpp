// Created by Ashechol on 2023/3/9.
// 33. 搜索旋转排序数组
// https://leetcode.cn/problems/search-in-rotated-sorted-array/

#include <iostream>
#include <vector>

using namespace std;

int search(vector<int>& nums, int target)
{
    int left = 0, right = nums.size();

    while (left < right)
    {
        int mid = left + ((right - left) >> 1);

        if (nums[mid] == target) return mid;

        if (nums[left] <= nums[mid])
        {
            if (nums[left] <= target && nums[mid] > target)
                right = mid;
            else
                left = mid + 1;
        }
        else
        {
            if (nums[mid] < target && target <= nums[right-1])
                left = mid + 1;
            else
                right = mid;
        }
    }

    return -1;
}

int main()
{
    vector<int> nums;

    int tmp;
    while (cin >> tmp)
    {
        nums.emplace_back(tmp);
        if (cin.get() == '\n') break;
    }
    cin >> tmp;

    cout << search(nums, tmp) << endl;
    return 0;
}
