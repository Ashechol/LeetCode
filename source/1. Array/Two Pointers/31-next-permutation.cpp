// Created by Ashechol on 2023/2/21.
// 31. 下一个排列
// https://leetcode.cn/problems/next-permutation/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void nextPermutation(vector<int>& nums)
{
    int n = nums.size();
    for (int pre = n - 1; pre >= 0; pre--)
    {
        for (int cur = pre - 1; cur >= 0; cur--)
        {
            if (nums[cur] < nums[pre])
            {
                swap(nums[cur], nums[pre]);
                reverse(nums.begin()+cur+1, nums.begin()+pre+1);
                return;
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int& num: nums) cin >> num;
    nextPermutation(nums);
    for (int& num: nums) cout << num << " ";
    cout << endl;
    return 0;
}