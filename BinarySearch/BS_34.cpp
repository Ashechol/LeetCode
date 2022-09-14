#include <iostream>
#include <vector>

using namespace std;

vector<int> searchRange(vector<int>& nums, int target);
int search(vector<int>& nums, int target, int left, int right);

int main()
{
    int n, target;
    cin >> n >> target;

    vector<int> nums(n);

    for (int& num: nums) cin >> num;

    for (const int num: searchRange(nums, target)) cout << num << " ";
    cout << endl;

    return 0;
}

vector<int> searchRange(vector<int>& nums, int target)
{
    int bg, ed;
    int left{0}, right{ static_cast<int>(nums.size()) };
    bg = ed = search(nums, target, left, right);

    if (bg == -1) return {-1, -1};

    // 对目标值左进行二分查找
    // 当找到的目标其左值不为目标值即为起始点
    while (bg - 1 >= left && nums[bg - 1] == target)
    {
        bg = search(nums, target, left, bg);
    }

    // 对目标值右进行二分查找
    // 当找到的目标其右值不为目标值即为终点
    while (ed + 1 < right && nums[ed + 1] == target)
    {
        ed = search(nums, target, ed + 1, right);
    }

    return {bg, ed};
}

// 二分查找（左闭右开）
int search(vector<int>& nums, int target, int left, int right)
{
    while (left < right)
    {
        int mid = ((right - left) >> 1) + left;

        if (nums[mid] == target) return mid;
        if (nums[mid] < target) left = mid + 1;
        if (nums[mid] > target) right = mid;
    }

    return -1;
}