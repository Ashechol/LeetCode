// 704. 二分查找
// 题目链接：https://leetcode.cn/problems/binary-search/
// 题解：https://www.wolai.com/4d217ahiXiWYHtpT8yCXAV

#include<iostream>
#include<vector>

using namespace std;

int n;

int search(vector<int>& nums, int target);

int main()
{
    int target;

    cin >> n >> target;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    cout << search(nums, target) << endl;

    return 0;
}

int search(vector<int>& nums, int target)
{
    int left = 0, right = nums.size();

    // 左闭右开
    while (left < right)
    {
        int mid = left + ((right - left) >> 1);

        if (nums[mid] == target) return mid;
        if (nums[mid] < target) left = mid + 1;
        if (nums[mid] > target) right = mid;
    }

    return -1;
}
