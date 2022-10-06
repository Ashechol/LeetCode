// Created by Ashechol on 2022/10/6.
// 18. 四数之和
// 题解链接：https://www.wolai.com/euc6U5B9iVLcitUun2KCZr#nFN6LxnvxhPhbBijcekdWV

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target);

int main()
{
    int n, t;
    cin >> n >> t;

    vector<int> nums(n);

    for (int& num: nums) cin >> num;

    vector<vector<int>> res = fourSum(nums, t);

    for (const auto& group: res)
    {
        cout << "[";

        for (int num: group)
            cout << num << " ";

        cout << "\b]";
    }

    cout << endl;

    return 0;
}

vector<vector<int>> fourSum(vector<int>& nums, int target)
{
    vector<vector<int>> res;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); i++)
    {
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        int t = target - nums[i];
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (j > i + 1 && nums[j] == nums[j - 1])
                continue;

            int l = j + 1, r = nums.size() - 1;
            while (l < r)
            {
                if (nums[j] + nums[l] + nums[r] < t)
                    l++;
                else if (nums[j] + nums[l] + nums[r] > t)
                    r--;
                else
                {
                    res.push_back({nums[i], nums[j], nums[l], nums[r]});

                    while (l < r && nums[l + 1] == nums[l]) l++;
                    while (l < r && nums[r - 1] == nums[r]) r--;

                    l++; r--;
                }
            }
        }
    }

    return res;
}