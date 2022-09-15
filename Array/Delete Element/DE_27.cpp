// Created by Ashechol on 2022/9/15.
// 27. 移除元素
// 题目链接：https://leetcode.cn/problems/remove-element/
// 题解链接：

#include <iostream>
#include <vector>

using namespace std;

int removeElement(vector<int>& nums, int val);
int removeElement_brute(vector<int>& nums, int val);
void removeElement_std(vector<int>& nums, int val);

int main()
{
    int n, val;
    cin >> n >> val;

    vector<int> nums(n);

    for (int& num: nums) cin >> num;

    // 快慢指针法
    int length = removeElement(nums, val);

    for (int i{0}; i < length; i++)
        cout << nums[i] << " ";

    // 使用标准库的函数来删除
    // removeElement_std(nums, val);
    //
    // for(int num: nums) cout << num << " ";

    cout << "\b\n";
}

// 快慢指针（双指针）
int removeElement(vector<int>& nums, int val)
{
    int slowIndex{0};

    // 快指针遍历全部数组
    for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++)
    {
        // 当快指针的值不为待覆盖值时
        // 慢指针值即为快指针的值
        // 且慢指针也向后移动
        if (nums[fastIndex] != val)
            nums[slowIndex++] = nums[fastIndex];
    }

    // 慢指针最后所对应的序号即为覆盖删除后的新长度
    return slowIndex;
}

int removeElement_brute(vector<int>& nums, int val)
{
    int length = static_cast<int>(nums.size());

    for (int i = 0; i < length; i++)
    {
        if (nums[i] == val)
        {
            for (int j = i; j < length - 1; j++)
                nums[j] = nums[j+1];

            length--;
            i--; // 因为被覆盖了，所以需要往前移
        }
    }

    return length;
}

// 使用标准库
void removeElement_std(vector<int>& nums, int val)
{
    // for (auto iter = nums.begin(); iter != nums.end(); )
    // {
    //     if (*iter == val) iter = nums.erase(iter);
    //     else iter++;
    // }

    // 此处std::remove相当于removeElement，只覆盖不释放多余的空间
    // std::remove返回了一个数组最后的迭代器
    auto newEnd = remove(nums.begin(), nums.end(), val);

    // 删除多余的空间
    nums.erase(newEnd, nums.end());

}