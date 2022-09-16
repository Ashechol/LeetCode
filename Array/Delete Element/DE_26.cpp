// Created by Ashechol on 2022/9/16.
// 26. 删除有序数组中的重复项
// 题目链接：https://leetcode.cn/problems/remove-duplicates-from-sorted-array/
// 题解链接：

#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int>& nums);

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);

    for (int& num: nums) cin >> num;

    int length{ removeDuplicates(nums) };

    for (int i{0}; i < length; i++) cout << nums[i] << " ";

    cout << "\b\n";
}

int removeDuplicates(vector<int>& nums)
{
    int length = (int) nums.size();

    if (length == 0) return 0;

    int slow{1};

    for (int fast{1}; fast < length; fast++)
    {
        if (nums[fast] != nums[fast - 1])
        {
            nums[slow++] = nums[fast];
        }
    }

    return slow;
}
