// Created by Ashechol on 2022/9/29.
// 1. 两数之和
// 题解链接：https://www.wolai.com/euc6U5B9iVLcitUun2KCZr#qJpAx4bfdigpVTacUYhpXw

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target);
vector<int> twoSum_compact(vector<int>& nums, int target);

int main()
{
    int n, t;
    cin >> n >> t;

    vector<int> nums(n);

    for (int& num: nums) cin >> num;

    for (int num: twoSum_compact(nums, t))
        cout << num << " ";

    cout << "\b\n";

    return 0;
}

vector<int> twoSum(vector<int>& nums, int target)
{
    unordered_multimap<int, int> numHash;
    vector<int> res(2);

    for (int i = 0; i < nums.size(); i++)
        numHash.insert(pair<int, int>(nums[i], i));

    for (int& num : nums)
    {
        res[0] = numHash.find(num)->second;
        numHash.erase(numHash.find(num));
        if (numHash.find(target - num) != numHash.end())
        {
            res[1] = numHash.find(target - num)->second;
            break;
        }
    }

    return res;
}

vector<int> twoSum_compact(vector<int>& nums, int target)
{
    unordered_map<int, int> numHash;

    for (int i = 0; i < nums.size(); i++)
    {
        if (numHash.find(target - nums[i]) != numHash.end())
            return {i, numHash[target - nums[i]]};

        numHash[nums[i]] = i;
    }

    return {};
}
