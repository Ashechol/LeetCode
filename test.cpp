#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_set>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums)
{
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++)
    {
        if (i > 0 && nums[i] == nums[i-1]) continue;

        int l = i + 1, r = nums.size() - 1;
        while (l < r)
        {
            int sum = nums[l] + nums[r] + nums[i];
            if (sum == 0)
            {
                res.push_back({nums[i], nums[l], nums[r]});
                while (l < r && nums[l] == nums[l+1]) l++;
                while (l < r && nums[r] == nums[r-1]) r--;
                l++; r--;
            }
            else if (sum > 0)
                r--;
            else
                l++;
        }
    }

    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int& num: nums) cin >> num;
    vector<vector<int>> res = threeSum(nums);
    for (vector<int>& ans: res)
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << "\n "[i != ans.size()-1];
    return 0;
}