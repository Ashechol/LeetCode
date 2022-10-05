// Created by Ashechol on 2022/10/5.
// 15. 三数之和
// 题解链接：https://www.wolai.com/euc6U5B9iVLcitUun2KCZr#9KLkbnmqyNyt3iJ1NeXbKa

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums);

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);

    for (int& num: nums) cin >> num;

    vector<vector<int>> res = threeSum(nums);

    for (const auto& group: res)
    {
        for (int num: group) cout << num << " ";
        cout << "\b\n";
    }

    return 0;
}

vector<vector<int>> threeSum(vector<int>& nums)
{
    vector<vector<int>> res;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > 0) return res;

        if (i > 0 && nums[i] == nums[i - 1]) continue;

        int l = i + 1, r = nums.size() - 1;

        while (l < r)
        {
            if (nums[i] + nums[l] + nums[r] > 0)
                r--;
            else if (nums[i] + nums[l] + nums[r] < 0)
                l++;
            else
            {
                res.push_back({nums[i], nums[l], nums[r]});

                while (l < r && nums[r] == nums[r - 1]) r--;
                while (l < r && nums[l] == nums[l + 1]) l++;

                l++; r--;
            }
        }
    }

    return res;
}
