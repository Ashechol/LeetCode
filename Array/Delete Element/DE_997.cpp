// Created by Ashechol on 2022/9/16.
// 977. 有序数组的平方
// 题目链接：https://leetcode.cn/problems/squares-of-a-sorted-array/
// 题解链接：

#include <iostream>
#include <vector>

using namespace std;

vector<int> sortedSquares(vector<int>& nums);

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int& num: nums) cin >> num;

    vector<int> ans = sortedSquares(nums);
    for (int num: ans) cout << num << " ";
    cout << "\b\n";

    return 0;
}

vector<int> sortedSquares(vector<int>& nums)
{
    int index = (int)nums.size();

    vector<int> newNums(index);
    int left = 0, right = index - 1;

    while (left <= right)
    {
        int sqrLeft = nums[left] * nums[left];
        int sqrRight = nums[right] * nums[right];

        if (sqrLeft > sqrRight)
        {
            newNums[--index] = sqrLeft;
            left++;
        }
        else
        {
            newNums[--index] = sqrRight;
            right--;
        }
    }

    return newNums;
}